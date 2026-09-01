$ErrorActionPreference = "Stop"

$shareName = "CYBR-Labs"
$hostFolder = "C:\CYBR-Labs"
$repoZip = "https://github.com/kmuchiri-tech/442-552/archive/refs/heads/main.zip"
$tempRoot = Join-Path $env:TEMP "cybr442-vbox-setup"
$zipPath = Join-Path $tempRoot "442-552-main.zip"
$extractPath = Join-Path $tempRoot "extract"
$vboxManage = Join-Path $env:ProgramFiles "Oracle\VirtualBox\VBoxManage.exe"

if (-not (Test-Path $vboxManage)) {
    throw "VBoxManage.exe was not found. Install Oracle VirtualBox or correct the installation path."
}

Write-Host ""
Write-Host "Available VirtualBox machines:" -ForegroundColor Cyan
$machines = & $vboxManage list vms
if (-not $machines) { throw "No VirtualBox machines were found." }
$machines | ForEach-Object { Write-Host "  $_" }

$vmName = Read-Host "Enter the Ubuntu VM name exactly as shown"
$vmInfo = & $vboxManage showvminfo $vmName --machinereadable 2>$null
if (-not $vmInfo) { throw "The selected VM was not found." }
if ($vmInfo -match 'VMState="running"' -or $vmInfo -match 'VMState="paused"') {
    throw "Power off the VM before adding the permanent shared folder."
}

New-Item -ItemType Directory -Force -Path $hostFolder | Out-Null
Remove-Item -Recurse -Force $tempRoot -ErrorAction SilentlyContinue
New-Item -ItemType Directory -Force -Path $tempRoot | Out-Null

Write-Host "Downloading the CYBR 442/552 repository..." -ForegroundColor Cyan
Invoke-WebRequest -Uri $repoZip -OutFile $zipPath
Expand-Archive -Path $zipPath -DestinationPath $extractPath -Force

$sourceRepo = Join-Path $extractPath "442-552-main"
$destinationRepo = Join-Path $hostFolder "442-552"
Remove-Item -Recurse -Force $destinationRepo -ErrorAction SilentlyContinue
Copy-Item -Recurse -Force $sourceRepo $destinationRepo

& $vboxManage sharedfolder remove $vmName --name $shareName 2>$null
& $vboxManage sharedfolder add $vmName --name $shareName --hostpath $hostFolder --automount

Write-Host ""
Write-Host "Shared folder configured successfully." -ForegroundColor Green
Write-Host "VM: $vmName"
Write-Host "Windows folder: $hostFolder"
Write-Host "Share name: $shareName"
Write-Host "Expected Ubuntu path: /media/sf_$shareName"
Write-Host ""
Write-Host "Start Ubuntu, then run setup-ubuntu-guest.sh inside the VM."
