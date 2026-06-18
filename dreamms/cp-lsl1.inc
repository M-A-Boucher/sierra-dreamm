$(include cp-lsl1-answers.inc)
$(include font-hercules.inc)

script[cp]:
    code = [[[$(CRLF)
        mode = prop("composite") ? prop("composite") : prop("videohw");
        mode = prop("machine") == "tandy" ? prop("machine") : mode;

        echo(mode);

        last_question = "";

        func update()
        {
          if (!script_running(cpscript))
          {
            if (mode == "hercules")
              str = scraper_string("BAA7C@@9n", "herc", 0x1);
            else if (mode == "cga")
              str = scraper_string("BAA64@@9c", "8x8", 0x3);
            else if (mode == "oldcga")
              str = scraper_string("BAA64@@9c", "8x8", 0x3, SF_HALFWIDTH);
            else
              str = scraper_string("BAA64@@9c", "8x8", 0xF);


            if (str == "Pleaseanswera,b,c,ord:")
            {
              if (mode == "hercules")
                text = scraper_string("IAAPR@@R2AAR2@@UaAAUa@@W@AAW@@@ZkAAZk@@cJAAcJ@@euAAeu@@hSAAhS@@j3", "herc", 0x0);
              else if (mode == "oldcga")
                text = scraper_string("QAAHs@@KPAAKP@@MzAAMz@@PXAAPX@@R7AAR7@@UfAAUf@@XDAAXD@@ZmAAZm@@cKAAcK@@euAAeu@@hSAAhS@@j2AAj2@@maAAma@@o9AAo9@@rhAArh@@uFAAuF@@wp
", "8x8", 0x0, SF_HALFWIDTH);
              else
                text = scraper_string("QAAHs@@KPAAKP@@MzAAMz@@PXAAPX@@R7AAR7@@UfAAUf@@XDAAXD@@ZmAAZm@@cKAAcK@@euAAeu@@hSAAhS@@j2AAj2@@maAAma@@o9AAo9@@rhAArh@@uFAAuF@@wp
", "8x8", 0x0);

              question = substr(text, 0, strstr(text, "a."));
              answer = strmap(question, "$$(CPANSWERS)");

              if (question != last_question)
              {
                echo("Text: " + text);
                echo("Question: " + question);
                echo("Answer: " + answer);
                last_question = question;

                if (!prop("noautocp")) 
                  cpscript = script_run_async("cpauto", answer+"\r");

                if (!prop("notextcp"))
                  overlay_show("cpoverlay", 1, "The correct answer is: " + answer);
              }
            }
            else
            {
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
