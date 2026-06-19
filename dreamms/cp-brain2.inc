COORDS = [[[|
    =
    a=48 167  // Cerebelum Rock
    b=165 144 // Cerebral Aqueduct
    c=203 61  // Corpus Callosum Mountains
    d=307 107 // Frontal Lobe Islands
    e=41 147  // Harbor Vitae
    f=148 129 // Hypothalamus Sea
    g=131 113 // Isle of Thalamus
    h=252 187 // Lake Pituitary
    i=76 149  // Land of Medulla Oblongata
    j=278 156 // Olfactory Lagoon
    k=167 188 // Pons Island
    l=154 43  // Sea of Cortex
    m=193 98  // Ventricle Bay
]]]

ISLAND_COORDS = [[[|
    =
    a=Cerebellum Rock: 83° S, 53° W
    b=Cerebral Aqueduct: 60° S, 64° E
    c=Corpus Callosum Mountains: 23° N, 102° E
    d=Frontal Lobe Islands: 23° S, 206° E
    e=Harbor Vitae: 63° S. 60° W
    f=Hypothalamus Sea: 45° S, 47° E
    g=Isle of Thalamus: 29° S, 30° E
    h=Lake Pituitary: 103° S, 151° E
    i=Land of Medulla Oblongata: 65° S, 25° W
    j=Olfactory Lagoon: 72° S, 177° E
    k=Pons Island: 104° S, 66° E
    l=Sea of Cortex: 41° N, 53° E
    m=Ventricle Bay: 14° S, 92° E
]]]

charset[vga]:
    height = 11
    char[a]: bits = 200`400`400`200`1f0`1f0`200`400`400`200
    char[b]: bits = 040`4c0`340`040`040`7f8`040`040
    char[c]: bits = 408`410`4a0`4c0`480`540`620`440
    char[d]: bits = 430`248`148`150`2a0`4a0`490`308
    char[e]: bits = 120`248`154`4e0`3f8`0e4`550`348`090
    char[f]: bits = 080`080`080`680`9fc`9fc`680`080`080`080
    char[g]: bits = 800`c04`30c`094`064`064`094`30c`c04`800
    char[h]: bits = 0c0`120`210`408`ffc`408`210`120`0c0
    char[i]: bits = 080`180`290`490`8fc`8fc`490`290`180`080
    char[j]: bits = 020`060`0a0`d24`3fc`3fc`d24`0a0`060`020
    char[k]: bits = 780`200`218`224`7e4`224`218`200`780
    char[l]: bits = 010`310`c90`4fc`c90`310`010
    char[m]: bits = c00`200`110`110`ffc`110`110`200`c00 
end

charset[ega]:
    height = 11
    char[a]: bits = 200`000`400`000`400`000`200`000`1f0`000`1f0`000`200`000`400`000`400`000`200
    char[b]: bits = 040`000`4c0`000`340`000`040`000`040`000`7f8`000`040`000`040
    char[c]: bits = 408`000`410`000`4a0`000`4c0`000`480`000`540`000`620`000`440
    char[d]: bits = 430`000`248`000`148`000`150`000`2a0`000`4a0`000`490`000`308
    char[e]: bits = 120`000`248`000`154`000`4e0`000`3f8`000`0e4`000`550`000`348`000`090
    char[f]: bits = 080`000`080`000`080`000`680`000`9fc`000`9fc`000`680`000`080`000`080`000`080
    char[g]: bits = 800`000`c04`000`30c`000`094`000`064`000`064`000`094`000`30c`000`c04`000`800
    char[h]: bits = 0c0`000`120`000`210`000`408`000`ffc`000`408`000`210`000`120`000`0c0
    char[i]: bits = 080`000`180`000`290`000`490`000`8fc`000`8fc`000`490`000`290`000`180`000`080
    char[j]: bits = 020`000`060`000`0a0`000`d24`000`3fc`000`3fc`000`d24`000`0a0`000`060`000`020
    char[k]: bits = 780`000`200`000`218`000`224`000`7e4`000`224`000`218`000`200`000`780
    char[l]: bits = 010`000`310`000`c90`000`4fc`000`c90`000`310`000`010
    char[m]: bits = c00`000`200`000`110`000`110`000`ffc`000`110`000`110`000`200`000`c00
end

script[cp]:
    code = [[[$(CRLF)
        cpactive = "";
        mouse_force_relative_zero(true);

        func update()
        {
          if (!script_running(cpscript))
          {
            glyph = scraper_string("BAAEK@@Hs", prop("videohw"), [0x4,0x10]);

            if (glyph != "")
            {
              coords = strmap(glyph, "$$(COORDS)");
              
              if (coords != cpactive)
              {
                echo("Glyph: " + glyph);
                echo("Coords: " + coords);

                cpactive = coords;

                if (!prop("noautocp"))
                  cpscript = script_run_async("cpauto", coords);

                if (!prop("notextcp"))
                  overlay_show("cpoverlay", -1, strmap(glyph, "$$(ISLAND_COORDS)"));
              }
            }
            else
            {
              cpactive = "";
              overlay_hide("cpoverlay");
            }
          }
        }

        func cpauto(coords)
        {
          input_lockout(true);
          sleep(2000);
          x = strword(0, coords);
          y = strword(1, coords);
          echo("Moving horizontal slide rule to: " + x);
          mouse_move_abs(mouse_pos_abs()[0], y-10); mouse_click(0); // -10 to take into account the slide rule thickness
          sleep(1000);
          echo("Moving vertical slide rule to: " + y);
          mouse_move_abs(2*x, y); mouse_click(0);
          sleep(1000);
          mouse_click(0); // Click on middle of coordinate
          sleep(500);
          input_lockout(false);
        }
    ]]]
end
