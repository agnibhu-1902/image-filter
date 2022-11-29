# image-filter
A command-line program that adds a blur, greyscale, reflection or sepia filter to an image.
> Run the 'filter' executable from the command-line.
### How to compile?
> Make sure 'clang' and 'make' are installed.
```
make filter
```
### Usage:
```
./filter [flag] infile outfile
```
### Flags used:
- **b:** Adds blur filter
- **g:** Adds greyscale filter
- **r:** Adds reflection filter
- **s:** Adds sepia filter
### Sample command:
```
./filter -b images/tower.bmp images/tower_blurred.bmp
```
> **_Note_:** This is a Linux-based project and may not work natively on Windows. Run it under a WSL shell environment.
>
> Documentation: https://learn.microsoft.com/en-us/windows/wsl
