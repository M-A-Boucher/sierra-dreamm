$(include font-8x8.inc)
$(include font-hercules.inc)
$(include cp-kq4-answers.inc)

script[cp]:
    code = [[[$(CRLF)
        mode = prop("composite") ? prop("composite") : prop("videohw");
        mode = prop("machine") == "tandy" ? prop("machine") : mode;

        cpactive = "";

        func update()
        {
          if (!script_running(cpscript))
          {
            if (mode == "hercules")
              str = scraper_string("BAAPR@@R2", "herc", 0);
            else if (mode == "oldcga")
              str = scraper_string("BIAPX2AR7", "8x8", 0, SF_HALFWIDTH);
            else
              str = scraper_string("BIAPX2AR7", "8x8", 0);

            if (str == "Inordertoverifyyourlegal")
            {
              if (mode == "hercules")
                question = scraper_string("FAAeu@@hSAAhS@@j3AAj3@@mcAAmc@@pBAApB@@rm", "herc", 0);
              else // Every other mode with a check on composite
                question = scraper_string("IAAeu@@hSAAhS@@j2AAj2@@maAAma@@o9AAo9@@rhAArh@@uFAAuF@@wpAAwp@@zN", "8x8", 0, mode == "oldcga" ? SF_HALFWIDTH : 0);

              answer = strmap(question, "$$(CPANSWERS)");

              if (answer != "" && cpactive == "")
              {
                cpactive = answer;

                echo("Question: " + question);
                echo("Answer: " + answer);

                if (!prop("noautocp"))
                  cpscript = script_run_async("cpauto", answer+"\r");

                if (!prop("notextcp"))
                  overlay_show("cpoverlay", 1, "The correct answer is: " + answer);
              }
            }
            else
            {
              cpactive = "";
              overlay_hide("cpoverlay");
            }
          }
        }

        func cpauto(value)
        {
          input_lockout(true);
          sleep(1000);
          keyboard_type(value);
          sleep(500);
          input_lockout(false);
        }
    ]]]
end
