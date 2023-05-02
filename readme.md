# Optim for optimus-manager

## Simple GUI to change Graphic Card

### How to install

```bash
git clone git@github.com:MaximeLeBesnerais/Optim.git ~/.config/Optim
cd ~/.config/Optim
make
sudo cp ./Optim /usr/bin/Optim
sudo cp ./assets/nvdia_logo.jpg /usr/share/icons/nvidia_logo.jpg
sudo desktop-file-install ./optim.desktop
cd -
```

### Usage

This program uses optimus-manager, so it MUST be installed and functional.
Click on a button to changes the Graphic Card to apply.
Click on apply to change graphic card (you will be logged out).

On error, the program will display an error, and not proceed further.

