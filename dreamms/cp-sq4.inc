charset[symbols]:
    height = 16
    char[a]: bits = 0220`02a0`03e0`0`0ff0`0800`09c0`0a20`0aa0`0ae0`0800`0800                    // cuberoot(G) - XW
    char[b]: bits = 0080`0040`0020`0ff0`0800`0900`0a00`0be0`0a00`0a00`0900`09e0`0900`0a00`0800  // sqr(pi) - AO
    char[c]: bits = 0010`0008`0004`7d7e`5140`6d40`0140`7d62`556a`4554`0040`0040`0040            // RE/sqr(3) - ER
    char[d]: bits = 4170`7d10`417c`0110`2500`5538`4944`0138`7d00`2148`1158`7d28                 // TSN/40^2 - SR
    char[e]: bits = 793c`0550`0950`053c`7900`0138`3d44`5144`5138`3d00                           // WA/AO - AW
end

FINGERPRINTS = [[[,
    G0v5mZlEbxb151bSs816YxDyUKYBb#Ny4pOLwA4ax#NHUO35MmYRFT=EGA
    7j6iKeQ49UTwmYkks5RVgSrw#U#HL89LiVWJZ2MxJ7QjAKj8nsDaNW=VGA
]]]

script[cp]:
    code = [[[$(CRLF)
        VALUE_MAP = "=;a=XW;b=AO;c=ER;d=SR;e=AW";
        answer = "";

        func update()
        {
          if (!script_running(cpscript))
          {
            cpactive = scraper_match("BsNSk3AXX", "$$(FINGERPRINTS)", MF_MOUSE) || scraper_match("BsNS42zXD", fingerprint, MF_MOUSE);

            if (cpactive)
            {
              text = scraper_string("BtmY91meF", "symbols", [0x6,0x1C]);

              answer = strmap(substr(text,0,1), VALUE_MAP) + strmap(substr(text,1,1), VALUE_MAP);
              echo("Answer: " + answer);

              if (answer != "")
              {
                if (!prop("noautocp"))
                  cpscript = script_run_async("cpauto", answer+"\r");

                if (!prop("notextcp"))
                  overlay_show("cpoverlay", 1, "Your janitorial intuition compels you to punch in this code: " + answer);
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
          keyboard_type(value, 500);
          sleep(500);
          input_lockout(false);
        }
    ]]]
end