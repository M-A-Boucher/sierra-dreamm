$(include cp-lsl1-answers.inc)

COMPOSITE = 0

script[cp]:
    code = [[[$(CRLF)
        last_question = "";

        func update()
        {
          if (!script_running(cpscript))
          {
            str = scraper_string("BAA64@@9c", "8x8", [0x3,0xF], "$$(COMPOSITE)");
            if (str == "Pleaseanswera,b,c,ord:")
            {
              cpactive = true;

              text = scraper_string("QAAHs@@KPAAKP@@MzAAMz@@PXAAPX@@R7AAR7@@UfAAUf@@XDAAXD@@ZmAAZm@@cKAAcK@@euAAeu@@hSAAhS@@j2AAj2@@maAAma@@o9AAo9@@rhAArh@@uFAAuF@@wp", "8x8", 0, "$$(COMPOSITE)");

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
