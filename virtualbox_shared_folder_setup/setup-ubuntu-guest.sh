#!/usr/bin/env bash
set -euo pipefail

share_name="CYBR-Labs"
auto_mount="/media/sf_CYBR-Labs"
manual_mount="/mnt/cybr-labs"
destination="$HOME/CYBR-Labs"
source_path=""

echo "Installing VirtualBox shared-folder support..."
sudo apt update
sudo apt install -y virtualbox-guest-utils virtualbox-guest-x11
sudo usermod -aG vboxsf "$USER"
sudo modprobe vboxsf

if [[ -d "$auto_mount/442-552" ]]; then
    source_path="$auto_mount/442-552"
else
    sudo mkdir -p "$manual_mount"
    if ! mountpoint -q "$manual_mount"; then
        sudo mount -t vboxsf -o "uid=$(id -u),gid=$(id -g)" "$share_name" "$manual_mount"
    fi
    source_path="$manual_mount/442-552"
fi

if [[ ! -d "$source_path" ]]; then
    echo "The 442-552 repository was not found in the shared folder."
    exit 1
fi

mkdir -p "$destination"
rm -rf "$destination/442-552"
cp -a "$source_path" "$destination/442-552"

echo
echo "Setup complete."
echo "Shared source: $source_path"
echo "Linux working copy: $destination/442-552"
echo
echo "cd "$destination/442-552/01_envvars_setuid""
echo "make"
echo
echo "Restart Ubuntu after today's work for permanent vboxsf group access."
