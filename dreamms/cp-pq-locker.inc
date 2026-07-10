charset[locker]:
    height = 5
    char[0]: bits = f8`88`f8
    char[1]: bits = f8
    char[2]: bits = b8`a8`e8
    char[3]: bits = a8`a8`f8
    char[4]: bits = e0`20`f8
    char[5]: bits = e8`a8`b8
    char[6]: bits = f8`a8`b8
    char[7]: bits = 80`80`f8
    char[8]: bits = f8`a8`f8
    char[9]: bits = e0`a0`f8
end

script[cp]:
    code = [[[$(CRLF)
        cpactive = "";

        func update()
        {
          if (!script_running(cpscript))
          {
            current_combination = scraper_string("$$(CP_REGION)", "locker", 0);

            if (cpactive == "unlocked")
            {
              cpactive = "";
              overlay_hide("cpoverlay");
            }

            if (strlen(current_combination) == 3 && current_combination != "$$(CP_LOCKER_COMBINATION)" && cpactive == "")
            {
              cpactive = "locked";
          
              if (!prop("noautocp"))
                cpscript = script_run_async("cpauto");

              if (!prop("notextcp"))
                overlay_show("cpoverlay", 1, "$$(CP_OVERLAY)");
            }
          }
        }

        func cpauto()
        {
          input_lockout(true);
          mouse_force_relative_zero(true);
          sleep(2000);
          x = strword(0, "$$(CP_COORDS)");
          y = strword(1, "$$(CP_COORDS)");

          mouse_move_abs(x*2, y); sleep(250);
          while (substr(current_combination, 0, 1) != substr("$$(CP_LOCKER_COMBINATION)", 0, 1) && current_combination != "") 
          {
            mouse_click(0);
            current_combination = scraper_string("$$(CP_REGION)", "locker", 0);
            sleep(250);
          }
          mouse_move_abs(x*2+30, y); sleep(250);
          while (substr(current_combination, 1, 1) != substr("$$(CP_LOCKER_COMBINATION)", 1, 1) && current_combination != "")
          {
            mouse_click(0);
            current_combination = scraper_string("$$(CP_REGION)", "locker", 0);
            sleep(250);
          }
          mouse_move_abs(x*2+60, y); sleep(250);
          while (substr(current_combination, 2, 1) != substr("$$(CP_LOCKER_COMBINATION)", 2, 1) && current_combination != "")
          {
            mouse_click(0);
            current_combination = scraper_string("$$(CP_REGION)", "locker", 0);
            sleep(250);
          }
          if ("$$(CP_LOCKER_COMBINATION)" == "269")
          {
            mouse_move_abs(x*2, 95); sleep(250);
            mouse_click(0); sleep(1000);
          }
          input_lockout(false);
          mouse_force_relative_zero(false);
          cpactive = "unlocked";
        }
    ]]]
end