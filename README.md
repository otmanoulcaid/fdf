# FdF @ 42

A simple 3D height-map renderer. You can rotate models, color is defined by
relative height in the map. More features planned!

<img width="444" alt="Screen Shot 2024-05-05 at 6 03 35 PM" src="https://github.com/otmanoulcaid/fdf/assets/57399454/5fa25e25-23dc-4280-9bd6-f58fa41dc91a">

<img width="1793" alt="Screen Shot 2024-05-05 at 4 33 50 PM" src="https://github.com/otmanoulcaid/fdf/assets/57399454/d97eed9a-d54c-4464-a474-3aaded05b834">

<img width="1796" alt="Screen Shot 2024-05-05 at 4 31 27 PM" src="https://github.com/otmanoulcaid/fdf/assets/57399454/47544ff4-7de5-40c9-a1ee-d8086c46154a">

## Features
* Simple file format definition (array of space-separated integers)
* 3D rotations with the mouse
* Camera controls (zoom, translate)
* Pretty color gradients!
* Double-buffered
* Line clipping

### Planned features
* Other projections (right now it's just orthographic)
* Different view modes: point map, wireframe, and filled
* More color modes: gradient, file-defined and z-buffer
* Depth shader
* Multithreaded calculations (OpenCL even?)
* Anti-aliased rendering
* Level-of-detail (less points when you zoom out on huge maps)

## Compiling and running
Run `make`. An executable will compile. Currently only tested on OS X.

Run it with `./fdf [map]`. A bunch of sample maps are provided in the `maps`
directory. The one in the screenshot above is `maps/42.fdf`.

Controls are: drag with left click to rotate, drag with right to zoom, drag with
both to move around.

## License
This project is licensed under the GNU General Public License 3.
