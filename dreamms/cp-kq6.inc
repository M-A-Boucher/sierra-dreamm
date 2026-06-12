FINGERPRINTS = [[[,
    bn0Y#WG4bcDyVi5AAygIoV3yFT@fv2vyk22LOquv95wsU1H#Saa0pU=1 // EGA
    DnVtfznHG1WBrf7giZ#tG4ttVF6UURzRHX0Vi0SUPnQL6BRgQQV2DW=1 // VGA
    mjLwCZ3dRM3yUT77M7XLu@DyiQLYn2cGejSDMfcHJ5vFeGD2q7NbJc=2 // EGA
    VrRa4TqpYch4#DNh1FhZ1IYzOYNho#cVjGA8eVPiXFx1@hw@eSa0CI=2 // VGA
    YkDkaZVlkXv7A6ijQ74zSfLyyyen@2kfB8mLC#W495CaGOX#NLnGRc=3 // EGA
    WU0KgrkcwAFAtPX#Cx5IuOBAyt7r4iLzYHQD44V0nkfnY9OIZpd4rj=3 // VGA
    @gEZ2Zf5PMzypcKf07XLu@DyiQLYn2cGejSDMfcHJ5vFeGD2q7NbJc=4 // EGA
    ucOrwT5x7q54siBdZFhZ1IYzOYNho#cVjGA8eVPiXFx1@hw@eSa0CI=4 // VGA
    Ch2huZgkKyr7dVJ5Q7dRNxbyjxBZr1JZspiLaLmPh5BcuV7#NqMQ1U=5 // EGA
    Qgf#QrIShW5AQsom#xE6@9Ftn2kU2GIK54LhhsHrTnF6expgkszL3W=5 // VGA
]]]

MOUSEMOVE_COORDS = [[[|
    =
    1=0=155 70;1=145 85;2=145 100;3=140 115
    2=0=141 95;1=158 95;2=151 124;3=235 124
    3=0=205 95;1=110 95;2=145 95
    4=0=158 95;1=200 110;2=185, 110;3=170, 150
    5=0=107 72;1=149 72;2=125 85;3=193 85;4=133 100;5=168 113
]]]

HINTS = [[[|
    =
    1="Only those pure of heart will be able to RISE the cliffs of logic."
    2=!!cliffs2.png!!
    3=Four men standing in a row,$(CRLF)Third from the left, and down you go,$(CRLF)The rest, in order, move you on,$(CRLF)The Youngest, the Oldest, and the Second Son.
    4=!!cliffs4.png!!
    5="Only those of the highest order may ASCEND the cliffs of logic."
]]]

script[mouse]:
    condition = is_game() || is_demo()
    code = mouse_force_relative_zero(true)
end

script[cp]:
    code = [[[$(CRLF)
        func update()
        {
          if (!script_running(cpscript))
          {
            cpactive = scraper_match("BTAEzsArN", "$$(FINGERPRINTS)", MF_MOUSE);

            if (cpactive)
            {
                if (!prop("noautocp"))
                  cpscript = script_run_async("cpauto", strmap(cpactive, "$$(MOUSEMOVE_COORDS)"));

                if (!prop("notextcp"))
                  overlay_show("cpoverlay", 1, strmap(cpactive, "$$(HINTS)"));
            }
            else
            {
              cpactive = "";
              overlay_hide("cpoverlay");
            }
          }
        }

        func cpauto(coords)
        {
          pos = 0;
          echo(coords);

          input_lockout(true);
          sleep(2000);
          mouse_move_abs(65, 5);  // Move to actionbar
          sleep(250);
          mouse_move_abs(65, 20); mouse_click(0); // Pick Hand icon

          for (i = 0; i<6; i++) 
          {
             coord = strmap(pos++, "=;"+coords);
             if (coord == "") break;
             sleep(750);
             mouse_move_abs(strword(0, coord), strword(1, coord)); mouse_click(0);
          }

          sleep(500);
          input_lockout(false);
        }
    ]]]
end