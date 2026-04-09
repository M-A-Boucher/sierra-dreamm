# sierra-dreamm

## How to use .dreamm files with DREAMM
To install these, create a folder called **ifsdreamm** next to wherever the DREAMM executable is installed. On macOS, this means going into the DREAMM.app package (right-click the DREAMM.app and select "Show Package Contents"), and creating an **ifsdreamm** folder inside `DREAMM.app/Contents/MacOS`.

Inside the **ifsdreamm** folder, you will need to create a folder called **game**. Inside **game** is where you put the `.dreamm` files.
Alternatively, if you run DREAMM from a command line, you can point DREAMM to any folder with a **game** folder with the `.dreamm` files with `-ifspath` option.

Launch DREAMM and you should now be able to import and play many Sierra (and Dynamix) adventure games in DREAMM.

Notes on AGI games with Softguard Superlok v2 copy protection, the agiscript currently doesn't work on the following titles:
- KQ3 v2.00, Int. 2.2.4.35, 2x720K and 3x360K
- KQ3 v2.14, Int. 2.935, 2x720K and 3x360K
- SQ1 v2.2, Int. 2.426
- SQ1 v2.2, Int. 2.917

All of the BC, KQ1, KQ2, LSL1, SQ2 and some early KQ3 and SQ1 copy protections get defeated with the script.
