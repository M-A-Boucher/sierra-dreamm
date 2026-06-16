charset[num]:
    height = 10
    char[0]: bits = 1f0`208`208`1f0
    char[0]: bits = 3e0`410`410`3e0
    char[1]: bits = 210`7f0`010
    char[2]: bits = 330`450`490`330
    char[3]: bits = 460`510`690`460
    char[4]: bits = 0c0`350`7f0`050
    char[5]: bits = 720`510`510`4e0
    char[6]: bits = 1e0`290`490`060
    char[7]: bits = 600`470`580`600
    char[8]: bits = 360`490`490`360
    char[9]: bits = 300`490`4a0`3c0
end

charset[chr]:
    height = 10
    char[']: bits = 700
    char[,]: bits = 004`018
    char[.]: bits = 010
    char[P]: bits = 410`7f0`490`480`480`300
    char[a]: bits = 0e0`110`110`120`0f0`010
    char[c]: bits = 0e0`110`110`110`0a0
    char[d]: bits = 0e0`110`110`510`7f0`010
    char[e]: bits = 0e0`150`150`150`0c0
    char[f]: bits = 110`3f0`510`400
    char[g]: bits = 0a8`154`154`194`108
    char[h]: bits = 410`7f0`110`100`110`0f0`010
    char[i]: bits = 110`5f0`010
    char[l]: bits = 410`7f0`010
    char[m]: bits = 110`1f0`110`100`110`0f0`110`100`110`0f0`010
    char[n]: bits = 110`1f0`110`100`110`0f0`010
    char[o]: bits = 0e0`110`110`110`0e0
    char[p]: bits = 104`1fc`114`110`110`0e0
    char[r]: bits = 110`1f0`090`100`100`100
    char[s]: bits = 090`150`150`150`120
    char[t]: bits = 100`7e0`110`020
    char[u]: bits = 100`1e0`010`010`110`1f0`010
end

script[cp]:
    code = [[[$(CRLF)
        cpactive = "";
        mouse_force_relative_zero(true);

        func update()
        {
          if (!script_running(cpscript))
          {
            match = substr(scraper_string("BAAje@@kz", "chr", 0x5), 0, 46);

            if (match == "Pleaseselect,inorder,thethreepartslistedonpage")
            {
              pageno = scraper_string("BAAje@@kz", "num", 0x5);
              echo("Page: " + pageno);

              answer = strmap(pageno, "$$(CPANSWERS)");
              answer1 = strword(0, answer);
              answer2 = strword(1, answer);
              answer3 = strword(2, answer);

              coords1 = strmap(answer1, "$$(COORDS)");
              coords2 = strmap(answer2, "$$(COORDS)");
              coords3 = strmap(answer3, "$$(COORDS)");

              if (answer != "" && !cpactive)
              {
                echo("Answer: " + answer1 + " " + answer2 + " " + answer3);
                cpactive = answer;

                if (!prop("noautocp"))
                  cpscript = script_run_async("cpauto", coords1, coords2, coords3);

                if (!prop("notextcp"))
                  overlay_show("cpoverlay", 1, "!!" + answer1 + ".png@200!! !!" + answer2 + ".png@200!! !!" + answer3 + ".png@200!!");
              }
            }
            else
            {
              cpactive = "";
              overlay_hide("cpoverlay");
            }
          }
        }

        func cpauto(coords1, coords2, coords3)
        {
          input_lockout(true);
          sleep(2000);
          x = 4*strword(0, coords1);
          y = 4*strword(1, coords1);
          echo("Moving mouse to X: " + x + "   Y: " + y);
          mouse_move_abs(x, y); mouse_click(0);
          x = 4*strword(0, coords2);
          y = 4*strword(1, coords2);
          echo("Moving mouse to X: " + x + "   Y: " + y);
          mouse_move_abs(x, y); mouse_click(0);
          x = 4*strword(0, coords3);
          y = 4*strword(1, coords3);
          echo("Moving mouse to X: " + x + "   Y: " + y);
          mouse_move_abs(x, y); mouse_click(0);
          sleep(500);
          input_lockout(false);
        }
    ]]]
end