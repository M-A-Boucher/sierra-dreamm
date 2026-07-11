charset[locker]:
    height = 7
    // VGA
    char[0]: bits = fe`82`ba`82`fe
    char[1]: bits = fe`fe`82`fe`fe
    char[2]: bits = fe`a2`aa`8a`fe
    char[3]: bits = fe`aa`aa`82`fe
    char[4]: bits = fe`8e`ee`82`fe
    char[5]: bits = fe`8a`aa`a2`fe
    char[6]: bits = fe`82`aa`a2`fe
    char[7]: bits = fe`be`be`82`fe
    char[8]: bits = fe`82`aa`82`fe
    char[9]: bits = fe`8e`ae`82`fe
    // EGA
    char[0]: bits = fe`fe`82`82`ba`ba`82`82`fe`fe
    char[1]: bits = fe`fe`fe`fe`82`82`fe`fe`fe`fe
    char[2]: bits = fe`fe`a2`a2`aa`aa`8a`8a`fe`fe
    char[3]: bits = fe`fe`aa`aa`aa`aa`82`82`fe`fe
    char[4]: bits = fe`fe`8e`8e`ee`ee`82`82`fe`fe
    char[5]: bits = fe`fe`8a`8a`aa`aa`a2`a2`fe`fe
    char[6]: bits = fe`fe`82`82`aa`aa`a2`a2`fe`fe
    char[7]: bits = fe`fe`be`be`be`be`82`82`fe`fe
    char[8]: bits = fe`fe`82`82`aa`aa`82`82`fe`fe
    char[9]: bits = fe`fe`8e`8e`ae`ae`82`82`fe`fe
end

script[cp]:
    code = [[[$(CRLF)
        PQ1 = prop("icon") == "sol-pq1-sci.png";
        REGION  = PQ1 ? ["BnANcoAPs","BqANcrAPs","BtANcuAPs"] : ["BMzYANzaP","BPzYAQzaP","BSzYATzaP"];
        LOCKER  = PQ1 ? [2,6,9] : [7,7,6];
        COORDS  = PQ1 ? [189,50] : [59,83];
        OVERLAY = PQ1 ? "!!gazette.png@400!!" : "!!policemanual.png@300!!";
        LOCKER_COMBINATION = LOCKER[0] + LOCKER[1] + LOCKER[2];

        cpactive = "";

        func update()
        {
          if (!script_running(cpscript))
          {
            updatecombination();

            if (cpactive == "unlocked")
            {
              cpactive = "";
              overlay_hide("cpoverlay");
            }

            if (strlen(current_combination) == 3 && current_combination != LOCKER_COMBINATION && cpactive == "")
            {
              cpactive = "locked";
          
              if (!prop("noautocp"))
                cpscript = script_run_async("cpauto");

              if (!prop("notextcp"))
                overlay_show("cpoverlay", 1, OVERLAY);
            }
          }
        }
   
        func updatecombination()
        {
          digit = [scraper_string(REGION[0], "locker", 0, SF_BGCOLOR),scraper_string(REGION[1], "locker", 0, SF_BGCOLOR),scraper_string(REGION[2], "locker", 0, SF_BGCOLOR)];
          current_combination = digit[0]+digit[1]+digit[2];
        }

        func cpauto()
        {
          input_lockout(true);
          mouse_force_relative_zero(true);
          sleep(1000);
          for (i = 0; i <= 2; i++)
          {
            mouse_move_abs(COORDS[0]*2+(i*30), COORDS[1]); sleep(250);
            while (digit[i] != LOCKER[i] && current_combination != "") 
            {
              mouse_click(0);
              updatecombination();
              sleep(150);
            }
          }
          if (current_combination == "269") // Old PQ1 locker model that you need to open manually
          {
            mouse_move_abs(COORDS[0]*2, 95); sleep(250);
            mouse_click(0);
            updatecombination();
            sleep(2000);
          }
          input_lockout(false);
          mouse_force_relative_zero(false);
          cpactive = "unlocked";
        }
    ]]]
end