FINGERPRINTS = [[[,
    coffKf#Rfozw5gxYQ8H9iLH05BAT@wMQE1iM8ggMl6dOn6H95v8FtT=EGA
    V1SoWdbDCCr9q6vII8cgHDr9cYkADwzPJeaMPp2Yp6XvnVTxzQWW9a=EGA
    yi83WWn6rbH8jnurs80ahG@8@HIln40NDseEaxQi96w@A1@1ZXgJNS=EGA
    0UQxSfoesq39CXKY881nqwf1A7JTfxUQ7S6JBMXZx6ETapz1x34mVa=EGA
    yFO7SfRPmvTwKK11U8rap170HYsRbwd7u22MWIvWV64VqeP9WdhC5T=MCGA
    pXtGXCd6kZB9oeay19dEQGGLmkJV9YridSLNZcXEv61i5zCK1PZwIR=VGA
    QDGscwT8qHq0qqBct9ET956YI#7dtxlGEIaNTxRkc1rcLBVpxLnLAt=VGA
    ITV@wtnkFht9A@Yul9v3kzyvaip4O6cO4yfNz9l5MuwVF5Riiuan0t=VGA
    axuIkwoWvRq0dbVE99n9mjdubEhsZxGzK4DNzKS6A3KomnNlK31CsR=VGA
]]]

CPANSWERS = [[[|
    =
    Asteroids=3 0 8 4
    AstralBodies=2 4 9 2
    BinarySystems=5 5 0 6
    BlackHoles=8 2 9 7
    Constellations=0 7 7 3
    Galaxies=8 7 9 3
    Gravity=4 1 6 0
    MagneticFields=8 2 8 2
    Meteors=6 9 0 1
    Moons=3 8 5 4
    Orbits=9 7 5 4
    PlanetaryFormations=1 6 4 0
    Pulsars=3 9 9 2
    Quadrants=4 4 2 6
    SolarFlares=5 6 1 3
    SolarSystems=6 3 6 3
    Stars=8 9 2 5
    VanAllenBelts=6 9 6 4
    WarpFields=7 0 0 1
]]]

COORDS = [[[|
    =
    0=242 183
    1=242 173
    2=252 173
    3=262 173
    4=242 163
    5=252 163
    6=262 163
    7=242 153
    8=252 153
    9=262 153
]]]
  
charset[sci]:
    height = 9
    char[!]: bits = fa0
    char["]: bits = c00`000`c00
    char[']: bits = 200`c00
    char[,]: bits = 010`020
    char[-]: bits = 100`100`100
    char[.]: bits = 020
    char[1]: bits = 420`fe0`020
    char[5]: bits = e40`a20`a20`9c0
    char[A]: bits = 7e0`900`900`7e0
    char[B]: bits = fe0`920`920
    char[B]: bits = fe0`920`920`6c0
    char[C]: bits = 7c0`820`820`440
    char[D]: bits = fe0`820`820`7c0
    char[F]: bits = fe0`900`900`800
    char[H]: bits = fe0`100`100
    char[J]: bits = 040`020`020`020`fc0
    char[M]: bits = fe0`400`300`400`fe0
    char[N]: bits = fe0`200`100`080`fe0
    char[R]: bits = fe0`900`900`6e0
    char[S]: bits = 640`920
    char[T]: bits = 800`800`fe0`800`800
    char[V]: bits = f80`040`020`040`f80
    char[W]: bits = fc0`020`0c0`020`fc0
    char[Y]: bits = e00`100`0e0`100`e00
    char[a]: bits = 040`2a0`2a0`1c0`020
    char[b]: bits = fc0`220`220`1c0
    char[c]: bits = 1c0`220`220`140
    char[d]: bits = 1c0`220`220`fc0
    char[e]: bits = 1c0`2a0`2a0`1a0
    char[e]: bits = 200`200`1e0
    char[f]: bits = 100`7e0`900`800
    char[g]: bits = 1c0`228`228`1f0
    char[h]: bits = fe0`200`200`1e0
    char[i]: bits = be0
    char[k]: bits = fe0`080`140`220
    char[l]: bits = fe0
    char[m]: bits = 3e0`200`200`1e0`200`200`1e0
    char[n]: bits = 3e0`100`200`1e0
    char[o]: bits = 1c0`220`220`1c0
    char[p]: bits = 3f0`240`240`180
    char[q]: bits = 180`240`240`3f0
    char[r]: bits = 3e0`100`200
    char[s]: bits = 120`2a0`2a0`240
    char[t]: bits = 200`fc0`220
    char[u]: bits = 3c0`020`020`3c0`020
    char[v]: bits = 380`040`020`040`380
    char[w]: bits = 3c0`020`3c0`020`3c0
    char[y]: bits = 380`050`050`3e0
    char[z]: bits = 260`2a0`320
end

script[cp]:
    code = [[[$(CRLF)
        cartridge = "";
        utterance = "";

        func update()
        {
          if (!script_running(cpscript))
          {
            utterance = scraper_string("BAAWa@@ZS", "sci", 0);

            if (substr(utterance, 0, 9) == "andutters" && cartridge == "")
            {
              utterance = substr(utterance, 10);
              cartridge = substr(utterance, 0, strstr(utterance, "\""));
              echo("Cartridge name: " + cartridge);
            }
            
            match = scraper_match("BAAAAMA@@", "$$(FINGERPRINTS)", MF_MOUSE);

            if (match && cartridge != "")
            {
              keypadcode = strmap(cartridge, "$$(CPANSWERS)");
              echo("Keypad code: " + keypadcode);

              if (!prop("noautocp"))
                cpscript = script_run_async("cpauto", keypadcode);

              if (!prop("notextcp"))
                overlay_show("cpoverlay", 1, "!!kp" + strword(0, keypadcode) + ".png!! !!kp" + strword(1, keypadcode) + ".png!! !!kp" + strword(2, keypadcode) + ".png!! !!kp" + strword(3, keypadcode) + ".png!!");
            }
            else
            {
              overlay_hide("cpoverlay");
            }

            found = scraper_string("BQmgAvNi4", "sci", 0);

            if (found == "Cartridgefound.Nowretrieving.")
            {
              cartridge = "";
              utterance = "";
              overlay_hide("cpoverlay");
            }
          }
        }

        func cpauto(keypadcode)
        {
          mouse_force_relative_zero(true);
          input_lockout(true);
          sleep(2000);
          mouse_move_abs(2*77, 7); 
          sleep(250);
          mouse_move_abs(2*77, 11);
          sleep(250);
          mouse_click(0); // Select Hand
          sleep(750);

          for (i = 0; i <= 3; i++) 
          {
             key = strword(i, keypadcode);
             coords = strmap(key, "$$(COORDS)");
             x = strword(0, coords);
             y = strword(1, coords);
             mouse_move_abs(2*x, y);
             sleep(250);
             mouse_click(0);
             sleep(750);
          }
          
          mouse_move_abs(2*276, 168); mouse_click(0); // 'ENTER'

          cartridge = "";
          sleep(500);
          input_lockout(false);
          mouse_force_relative_zero(false);
        }
    ]]]
end