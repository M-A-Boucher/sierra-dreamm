CPANSWERS = [[[|
    =
    1=dynamite star firework egg
    2=plus bomb cheese star
    3=aerial egg dynamite bomb
    4=egg plus star aerial
    5=bomb star dynamite cheese
    6=cheese firework star dynamite
    7=star dynamite egg firework
    8=dynamite bomb plus egg
    9=aerial star egg egg
    10=plus firework star dynamite
]]]

COORDS = [[[|
    =
    dynamite=356 250
    cheese=356 278
    egg=356 306
    star=356 334
    bomb=394 250
    aerial=394 278
    firework=394 306
    plus=394 334
]]]

charset[bb]:
    height = 13
    char[0]: bits = 1f00`3f80`4040`0000`4040`3f80`1f00
    char[1]: bits = 4040`7fc0`7fc0`0040
    char[2]: bits = 30c0`7080`02c0`44c0`7cc0`3980
    char[3]: bits = 3180`71c0`0000`4440`7fc0`3b80
    char[4]: bits = 0600`0a00`1200`0000`7fc0`7fc0`0200
    char[5]: bits = 6d80`65c0`6000`6440`67c0`4380
    char[6]: bits = 3f80`7fc0`4040`0400`77c0`3380
    char[7]: bits = 7000`2000`61c0`67c0`6e00`6000
    char[8]: bits = 3b80`7fc0`4440`0000`4440`7fc0`3b80
    char[9]: bits = 3980`7dc0`0400`4040`7fc0`3f80`0000
    char[0x53]: bits = 39c0`7cc0`4c00`0640`67c0`7380
    char[0x61]: bits = 0780`0fc0`0840`0000`0fc0`0fc0`0040
    char[0x65]: bits = 0780`0fc0`0840`0200`0a40`0ec0`0680
    char[0x67]: bits = 0790`0fd8`0840`0008`0ff8`0ff0`0800
    char[0x70]: bits = 0808`0ff8`0ff8`0008`0840`0fc0`0780
end

script[cp]:
    code = [[[$(CRLF)
        cpactive = "";

        func update()
        {
          if (!script_running(cpscript))
          {
            match = substr(scraper_string("BAAma@@ny", "bb", 0x4), 0, 7);

            if (match == "Seepage")
            {
              pageno = substr(scraper_string("BAAma@@ny", "bb", 0x4), 7);
              echo("Page: " + pageno);

              answer = strmap(pageno, "$$(CPANSWERS)");
              answer = [strword(0, answer),strword(1, answer),strword(2, answer),strword(3, answer)];

              coords = [strmap(answer[0], "$$(COORDS)"),strmap(answer[1], "$$(COORDS)"),strmap(answer[2], "$$(COORDS)"),strmap(answer[3], "$$(COORDS)")];

              if (answer != "" && !cpactive)
              {
                echo("Answer: " + answer);
                cpactive = answer;

                if (!prop("noautocp"))
                  cpscript = script_run_async("cpauto", coords);

                if (!prop("notextcp"))
                  overlay_show("cpoverlay", 1, "!!bb-" + answer[0] + ".png!! !!bb-" + answer[1] + ".png!! !!bb-" + answer[2] + ".png!! !!bb-" + answer[3] + ".png!!");
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
          mouse_force_relative_zero(true);
          input_lockout(true);
          sleep(2000);
          for (i = 0; i <= 3; i++)
          {
            x = strword(0, coords[i]);
            y = strword(1, coords[i]);
            echo("Moving mouse to X: " + x + "   Y: " + y);
            mouse_move_abs(x, y); mouse_click(0);
          }
          sleep(500);
          input_lockout(false);
          mouse_force_relative_zero(false);
        }
    ]]]
end