script[cp]:
    code = [[[$(CRLF)
        DO_IT = "0=233 45 TT(pick);1=540 45 TT(drop);2=233 100 PS(pick);3=540 100 PS(drop);4=233 155 SE(pick);5=540 155 SE(drop);6=233 210 RF(pick);7=540 210 RF(drop);8=233 265 FC(pick);9=540 265 FC(drop);10=520 45 TT(pick);11=255 100 TT(drop);12=540 100 REP(pick);13=600 100 REP(drop);14=540 155 FER(pick);15=600 155 FER(drop);16=540 210 DIM(pick);17=540 155 DIM(drop);18=520 155 SE(pick);19=255 265 SE(drop);20=540 265 SPN(pick);21=540 210 SPN(drop);22=520 210 RF(pick);23=255 45 RF(drop);24=600 155 FER(pick);25=540 100 FER(pick);26=520 100 PS(pick);27=255 155 PS(drop);28=600 100 REP(pick);29=540 265 REP(drop);30=520 265 FC(pick);31=255 210 FC(drop);32=410 45;33=385 100;34=315 155;35=365 210;36=340 265;37=465 295 CLOSE;38=460 25 POWER";

        func update()
        {
          if (!script_running(cpscript))
          {
            cpactive = scraper_match("BQAAAwACr", "MkMnjoGjxG6DFEbJ5K8JPTSa#d@K@5I@s5XjfmkjERvptJH55tCB0x", MF_MOUSE);

            if (cpactive)
            {
              arraya = scraper_match("BUTCirtJv", "ZvDAu7HyObTUyRIoJcJuwPfwYcO#buL3@HfTl@qi4YfzQQfrLwGicM", MF_MOUSE);
              arrayb = scraper_match("BUTJvrtRN", "GBTaX4LoMCrUdUYrhi8k4T7WKA0Qnv4SUATSeVkHwY9o4yzrF1wKYO", MF_MOUSE);
              arrayc = scraper_match("BUTRNrtYr", "CKiHe9LlJhmN11#jBhRFuWHWNN0RXt8c9TDRPfuHkY6GSoSP#WWrwO", MF_MOUSE);
              arrayd = scraper_match("BUNYrrtgJ", "P@rdq9zclrjUTdqkthpXStvWOebGDrbwLAvRBpwBgYEhM7roKbhT0N", MF_MOUSE);
              arraye = scraper_match("BUTgJrtnm", "OFYNO9AZSuDUOzqWBj5xBiHWYPEWzvOEZcvTKdQyAY4hEFbr5FweoM", MF_MOUSE);

              if (!prop("notextcp"))
                overlay_show("cpoverlay", 1, (arraya ? "!!datacorderadone.png!!$(CRLF)" : "!!datacordera.png!!$(CRLF)")+(arrayb ? "!!datacorderbdone.png!!$(CRLF)" : "!!datacorderb.png!!$(CRLF)")+(arrayc ? "!!datacordercdone.png!!$(CRLF)" : "!!datacorderc.png!!$(CRLF)")+(arrayd ? "!!datacorderddone.png!!$(CRLF)" : "!!datacorderd.png!!$(CRLF)")+(arraye ? "!!datacorderedone.png!!$(CRLF)" : "!!datacordere.png!!$(CRLF)"));

              if (!arraya && !arrayb && !arrayc && !arrayd && !arraye)
                if (!prop("noautocp"))
                  cpscript = script_run_async("cpauto", DO_IT);
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
          mouse_force_relative_zero(true);
          input_lockout(true);
          sleep(1000);
          for (i = 0; i<39; i++) 
          {
            coord = strmap(pos++, "=;"+coords);
            if (coord == "") break;
            sleep(750);
            mouse_move_abs(strword(0, coord), strword(1, coord)); mouse_click(0);
            echo(strword(2, coord) + " @ " + mouse_pos_abs());
          }
          sleep(500);
          mouse_force_relative_zero(false);

          input_lockout(false);
        }
    ]]]
end
