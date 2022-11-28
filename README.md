# image-filter
A command-line programme that adds a blur, greyscale, reflection or sepia filter to an image.
> Run the 'filter' executable from the command-line.
### Usage:
#### Windows:
```
.\filter.exe [flag] infile outfile
```
#### MacOS (Unix):
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
