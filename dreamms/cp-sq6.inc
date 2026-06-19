
nothrottle=25
script[cp]:
    code = [[[$(CRLF)
        DO_IT = "0=233 45 TT(pick);1=540 45 TT(drop);2=233 100 PS(pick);3=540 100 PS(drop);4=233 155 SE(pick);5=540 155 SE(drop);6=233 210 RF(pick);7=540 210 RF(drop);8=233, 265 FC(pick);9=540, 265 FC(drop);10=520, 45 TT(pick);11=255, 45 TT(drop);12=540, 100 REP(pick);13=600, 100 REP(drop);14=540, 155 FER(pick);15=600, 155 FER(drop);16=540, 155 DIM(pick);17=520, 155;18=255, 155;19=540, 210;20=410, 45;21=385, 100;22=315, 155;23=365, 210;24=340, 265;25=465, 295 CLOSE;26=460, 25 POWER";
                  mouse_force_relative_zero(true);

        func update()
        {
          if (!script_running(cpscript))
          {
            cpactive = scraper_match("BQAAAwACr", "MkMnjoGjxG6DFEbJ5K8JPTSa#d@K@5I@s5XjfmkjERvptJH55tCB0x", MF_MOUSE);
            arraya = scraper_match("BUTCirtJv", "ZvDAu7HyObTUyRIoJcJuwPfwYcO#buL3@HfTl@qi4YfzQQfrLwGicM", MF_MOUSE);
            arrayb = scraper_match("BUTJvrtRN", "GBTaX4LoMCrUdUYrhi8k4T7WKA0Qnv4SUATSeVkHwY9o4yzrF1wKYO", MF_MOUSE);
            arrayc = scraper_match("BUTRNrtYr", "CKiHe9LlJhmN11#jBhRFuWHWNN0RXt8c9TDRPfuHkY6GSoSP#WWrwO", MF_MOUSE);
            arrayd = scraper_match("BUNYrrtgJ", "P@rdq9zclrjUTdqkthpXStvWOebGDrbwLAvRBpwBgYEhM7roKbhT0N", MF_MOUSE);
            arraye = scraper_match("BUTgJrtnm", "OFYNO9AZSuDUOzqWBj5xBiHWYPEWzvOEZcvTKdQyAY4hEFbr5FweoM", MF_MOUSE);

            if (cpactive)
            {
              if (!prop("noautocp"))
                cpscript = script_run_async("cpauto", DO_IT);

              boardadone = scraper_match("BUTCirtJv", "ZvDAu7HyObTUyRIoJcJuwPfwYcO#buL3@HfTl@qi4YfzQQfrLwGicM", MF_MOUSE);
              boardbdone = scraper_match("BUTJvrtRN", "GBTaX4LoMCrUdUYrhi8k4T7WKA0Qnv4SUATSeVkHwY9o4yzrF1wKYO", MF_MOUSE);
              boardcdone = scraper_match("BUTRNrtYr", "CKiHe9LlJhmN11#jBhRFuWHWNN0RXt8c9TDRPfuHkY6GSoSP#WWrwO", MF_MOUSE);
              boardddone = scraper_match("BUNYrrtgJ", "P@rdq9zclrjUTdqkthpXStvWOebGDrbwLAvRBpwBgYEhM7roKbhT0N", MF_MOUSE);
              boardedone = scraper_match("BUTgJrtnm", "OFYNO9AZSuDUOzqWBj5xBiHWYPEWzvOEZcvTKdQyAY4hEFbr5FweoM", MF_MOUSE);

              if (!prop("notextcp"))
                overlay_show("cpoverlay", 1, (boardadone ? "!!datacorderadone.png!!$(CRLF)" : "!!datacordera.png!!$(CRLF)")+(boardbdone ? "!!datacorderbdone.png!!$(CRLF)" : "!!datacorderb.png!!$(CRLF)")+(boardcdone ? "!!datacordercdone.png!!$(CRLF)" : "!!datacorderc.png!!$(CRLF)")+(boardddone ? "!!datacorderddone.png!!$(CRLF)" : "!!datacorderd.png!!$(CRLF)")+(boardedone ? "!!datacorderedone.png!!$(CRLF)" : "!!datacordere.png!!$(CRLF)"));
            }
            else
            {
              overlay_hide("cpoverlay");
            }
          }
        }





        func cpauto(coords)
        {
          pos = 0;
          echo(coords);

          input_lockout(true);
          sleep(1000);
          for (i = 0; i<27; i++) 
          {
             coord = strmap(pos++, "=;"+coords);
             if (coord == "") break;
             sleep(750);
             echo(strword(2, coord) + " @ " + strword(0, coord) + "," + strword(1, coord));
             mouse_move_abs(strword(0, coord), strword(1, coord)); mouse_click(0);
          }
          sleep(500);
          mouse_force_relative_zero(false);
          input_lockout(false);
        }
    ]]]
end