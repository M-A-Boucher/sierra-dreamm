FINGERPRINTS = [[[,
    qMkJaZCs2LDzkqcfM8Mab1@ziOfED@NQ1TCM1yFdt4Ngqwn@PoC69T=locked
    j8MpKYK4#PDynlBDQ8Mab1@ziOfED@NQ1TCM1yFdt4Ngqwn@PoC69T=unlocked
]]]

script[cp]:
    code = [[[$(CRLF)
        cpactive = "";

        func update()
        {
          if (!script_running(cpscript))
          {
            if (locker == "unlocked" && cpactive == "locked")
            {
              cpactive = "";
              overlay_hide("cpoverlay");
            }

            locker = scraper_match("BkNVcoamF", "$$(FINGERPRINTS)", MF_MOUSE);

            if (locker == "locked" && cpactive == "")
            {
              cpactive = locker;
          
              if (!prop("noautocp"))
                cpscript = script_run_async("cpauto");

              if (!prop("notextcp"))
                overlay_show("cpoverlay", 1, "!!gazette.png@400!!");
            }
          }
        }

        func cpauto()
        {
          mouse_force_relative_zero(true);
          input_lockout(true);
          sleep(2000);
          mouse_move_abs(2*189, 50); sleep(250);
          mouse_click(0); sleep(250);
          mouse_click(0); sleep(250);
          mouse_move_abs(2*204, 40); sleep(250);
          mouse_click(0); sleep(250);
          mouse_click(0); sleep(250);
          mouse_click(0); sleep(250);
          mouse_click(0); sleep(250);
          mouse_move_abs(2*219, 40); sleep(250);
          mouse_click(0); sleep(250);
          mouse_move_abs(2*189, 95); sleep(250);
          mouse_click(0); sleep(1000);        
          locker = "unlocked";
          input_lockout(false);
          mouse_force_relative_zero(false);
        }
    ]]]
end