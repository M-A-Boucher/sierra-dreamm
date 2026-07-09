script[cp]:
    code = [[[$(CRLF)
        cpactive = "";

        func update()
        {
          if (!script_running(cpscript))
          {
            keypad = scraper_match("BpmZm0ztx", "pODceeBhoLj1o@zNA83ASK31nZAkv5YmNlyMU5dIp7Fejz75CUgLVW", MF_MOUSE);

            if (keypad)
            {
              if (cpactive == "")
              {
                cpactive = keypad;
              
                if (!prop("notextcp"))
                  overlay_show("cpoverlay", 1, "!!sq5dest.png@250!!");
              }
            }
            else
            {
              cpactive = "";
              overlay_hide("cpoverlay");
            }
          }
        }
    ]]]
end