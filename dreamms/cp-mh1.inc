$(include font-hercules.inc)

CPANSWERS = [[[|
    =
    Onpage2,whatisthethirdwordinthefirstparagraph?=selected
    Onpage2,whatistheseventhwordinthefirstparagraph?=position
    Onpage2,whatisthesixthwordinthesecondparagraph?=given
    Onpage2,whatisthefourthwordinthethirdparagraph?=issued
    Onpage2,whatisthesixthwordinthethirdparagraph?=Manhunter
    Onpage2,whatistheeighthwordinthethirdparagraph?=Device
    Onpage3,whatisthethirdwordinthesecondparagraph?=function
    Onpage3,whatisthefourthwordinthesecondparagraph?=provides
    Onpage3,whatisthefifthwordinthesecondparagraph?=access
    Onpage3,whatistheseventhwordinthesecondparagraph?=limited
    Onpage4,whatisthethirdwordinthefirstparagraph?=Manhunter
    Onpage4,whatisthesixthwordinthefirstparagraph?=required
    Onpage4,whatistheeighthwordinthefirstparagraph?=record
    Onpage4,whatisthetenthwordinthefirstparagraph?=pertinent
    Onpage4,whatisthesecondwordinthesecondparagraph?=human
    Onpage4,whatisthesecondwordinthethirdparagraph?=function
    Onpage4,whatisthethirdwordinthesecondparagraph?=movement
    Onpage4,whatisthefifthwordinthesecondparagraph?=recorded
    Onpage4,whatistheeighthwordinthesecondparagraph?=Human
    Onpage4,whatistheninthwordinthesecondparagraph?=Tracking
    Onpage4,whatisthesecondwordinthethirdparagraph?=function
    Onpage5,whatisthefourthwordinthefirstparagraph?=these
    Onpage5,whatisthesixthwordinthefirstparagraph?=subjects
    Onpage5,whatisthefifthwordinthesecondparagraph?=found
    Onpage5,whatistheninthwordinthesecondparagraph?=efficient
    Onpage6,whatisthesecondwordinthesecondparagraph?=Alliance
    Onpage6,whatisthethirdwordinthesecondparagraph?=central
    Onpage6,whatisthefourthwordinthesecondparagraph?=computer
    Onpage6,whatisthefifthwordinthesecondparagraph?=contains
    Onpage7,whatisthefourthwordinthefirstparagraph?=Animated
    Onpage7,whatisthefifthwordinthefirstparagraph?=Adventure
    Onpage7,whatisthesixthwordinthefirstparagraph?=Game
    Onpage7,whatistheseventhwordinthefirstparagraph?=simply
    Onpage7,whatistheeighthwordinthefirstparagraph?=stated
    Onpage10,whatisthethirdwordinthesecondparagraph?=begins
    Onpage10,whatisthefifthwordinthesecondparagraph?=years
    Onpage10,whatistheeighthwordinthesecondparagraph?=alien
    Onpage12,whatisthethirdwordinthefirstparagraph?=marker
    Onpage12,whatisthefourthwordinthefirstparagraph?=down
    Onpage12,whatisthefirstwordinthesecondparagraph?=Position
    Onpage12,whatisthesixthwordinthesecondparagraph?=front
    Onpage12,whatistheseventhwordinthefirstparagraph?=location
    Onpage12,whatistheninthwordinthefirstparagraph?=Trinity
    Onpage12,whatisthesixthwordinthefourthparagraph?=matches
    Onpage12,whatisthefifthwordintheseventhparagraph?=inventory
    Onpage12,whatistheeighthwordintheseventhparagraph?=receive
    Onpage12,whatisthethirdwordintheninthparagraph?=church
    Onpage12,whatisthefourthwordintheninthparagraph?=scene
    Onpage12,whatisthethirdwordinthetenthparagraph?=proceeds
    Onpage12,whatistheeighthwordinthetenthparagraph?=North
    Onpage12,whatistheninthwordinthetenthparagraph?=Brooklyn
    Onpage12,whatisthefifthwordintheeleventhparagraph?=travel
    Onpage13,whatisthesixthwordinthefirstparagraph?=video
    Onpage13,whatistheseventhwordinthefirstparagraph?=game
    Onpage13,whatisthelastwordinthefirstparagraph?=knife
    Onpage13,whatisthefourthwordinthesecondparagraph?=outside
    Onpage13,whatistheseventhwordinthesecondparagraph?=hand
]]]

script[cp]:
    code = [[[$(CRLF)
        func update()
        {
          if (!script_running(cpscript))
          {
            if (is_hercules())
              str = scraper_string("BONPXuNR7", "herc", 0);
            else
              str = scraper_string("BONPXuNR7", "8x8[21-7A]", 0, is_composite() ? SF_HALFWIDTH : 0);

            if (str == "AttentionManhunter!")
            {
              if (is_hercules())
                question = scraper_string("DAAma@@o9AAo9@@rhAArh@@uF", "herc", 0);
              else
                question = scraper_string("DAAma@@o9AAo9@@rhAArh@@uF", "8x8[21-7A]", 0, is_composite() ? SF_HALFWIDTH : 0);

              answer = strmap(question, "$$(CPANSWERS)");

              if (answer != "")
              {
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
