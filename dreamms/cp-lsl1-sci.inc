$(include cp-lsl1-answers.inc)

charset[lsl1]:
    height = 10
    char[!]: bits = 7d0
    char["]: bits = 600`000`600
    char[&]: bits = 060`290`510`2a0`440`1a0`010`010
    char[']: bits = 200`400
    char[(]: bits = 1c0`630`808
    char[)]: bits = 808`630`1c0
    char[,]: bits = 008`010
    char[-]: bits = 080`080`080`080`080
    char[.]: bits = 010
    char[0]: bits = 3e0`410`410`410`410`3e0
    char[1]: bits = 210`7f0`010
    char[2]: bits = 230`450`490`490`310
    char[3]: bits = 220`410`490`490`490`360
    char[4]: bits = 040`0c0`140`240`7f0
    char[5]: bits = 710`510`510`510`0e0
    char[7]: bits = 600`400`470`580`600
    char[9]: bits = 300`490`490`4a0`3c0
    char[:]: bits = 090
    char[;]: bits = 008`090
    char[?]: bits = 200`400`450`480`300
    char[A]: bits = 010`070`1d0`640`1d0`070`010
    char[B]: bits = 410`7f0`490`490`490`360
    char[C]: bits = 1c0`220`410`410`410`210`720
    char[D]: bits = 410`7f0`410`410`220`1c0
    char[E]: bits = 410`7f0`490`490`5d0`630
    char[F]: bits = 410`7f0`490`480`5c0`600
    char[G]: bits = 1c0`220`410`410`410`250`760`040
    char[H]: bits = 410`7f0`490`080`080`490`7f0`410
    char[I]: bits = 410`7f0`410
    char[J]: bits = 020`010`410`7e0`400
    char[K]: bits = 410`7f0`490`180`240`430`410`010
    char[L]: bits = 410`7f0`410`010`010`030
    char[M]: bits = 410`7f0`610`100`0c0`100`610`7f0`410
    char[N]: bits = 410`7f0`210`100`080`440`7f0`400
    char[O]: bits = 1c0`220`410`410`410`220`1c0
    char[P]: bits = 410`7f0`490`480`480`300
    char[R]: bits = 410`7f0`490`480`4c0`330`010
    char[S]: bits = 370`4a0`490`290`760
    char[T]: bits = 600`400`410`7f0`410`400`600
    char[U]: bits = 400`7e0`410`010`410`7e0`400
    char[V]: bits = 400`600`580`070`580`600`400
    char[W]: bits = 400`600`580`070`580`600`580`070`580`600`400
    char[Y]: bits = 400`600`110`0f0`110`600`400
    char[Z]: bits = 630`450`490`510`610`430
    char[_]: bits = 010`010`010`010`010`010`010`010`010`010`010`010`010`010`010`010`010`010`010`010`010`010`010`010`010`010`010`010`010`010
    char[a]: bits = 0a0`150`150`0e0`010
    char[b]: bits = 400`7e0`110`110`0e0
    char[c]: bits = 0e0`110`110`0a0
    char[d]: bits = 0e0`110`110`7e0`410
    char[e]: bits = 1c0`2a0`2a0`1a0
    char[e]: bits = 0e0`150`150`0d0
    char[f]: bits = 110`3f0`510`400
    char[g]: bits = 0a8`154`154`094`108
    char[h]: bits = 410`7f0`100`110`0f0`010
    char[i]: bits = 110`5f0`010
    char[j]: bits = 108`5f0
    char[k]: bits = 410`7f0`040`1b0`110
    char[l]: bits = 410`7f0`010
    char[m]: bits = 110`0f0`100`110`0f0`100`110`0f0`010
    char[n]: bits = 110`0f0`110`100`0f0`010
    char[o]: bits = 0e0`110`110`0e0
    char[p]: bits = 104`0fc`114`110`0e0
    char[q]: bits = 0e0`110`114`0fc`104
    char[r]: bits = 110`0f0`110`100
    char[s]: bits = 090`150`150`120
    char[t]: bits = 100`3e0`110
    char[u]: bits = 100`1e0`010`110`1e0`010
    char[v]: bits = 100`1c0`030`1c0`100
    char[w]: bits = 100`1c0`130`1c0`030`1c0`100
    char[x]: bits = 110`1b0`040`1b0`110
    char[y]: bits = 104`188`150`020`140`180`100
    char[z]: bits = 190`130`150`190`130
end

FINGERPRINTS = [[[,
    J4KKuesmB3D1jBJT48tOmt2yTDMHI38Jn1MZ8eNPU@CBSIByZshpnu=0x27 0x37 0x1D 0x2D 0x3D          // VGA
    J4KKuesmB3D1jBJT48Uo@071jUUAL5pC#a#M9tFRx#h7npf9d#oMBV=0x9 0xA 0xB 0xD 0xE               // EGA
    J4KKuesmB3D1jBJT486j61D1LRta@5TM6reM9tFRx#ycas65dJaMpV=0xAA0 0xB00B 0xE00E 0x9009 0xD00D // MCGA
]]]

script[cp]:
    code = [[[$(CRLF)
        last_question = "";

        func update()
        {
          if (!script_running(cpscript))
          {
            colors = scraper_match("BAAAA@@Gu", "$$(FINGERPRINTS)", MF_MOUSE);

            if (colors)
            {
              question = scraper_string("DAAHD@@KPAAKP@@NcAANc@@Qp", "lsl1", [int(strword(0,colors)),int(strword(1,colors)),int(strword(2,colors)),int(strword(3,colors)),int(strword(4,colors))]);

              if (question != last_question)
              {
                echo("Colors: " + colors);
                answer = strmap(question, "$$(CPANSWERS)");

                if (answer != "")
                {
                  echo("Question: " + question);
                  echo("Answer: " + answer);
                  last_question = question;

                  if (!prop("noautocp")) 
                    cpscript = script_run_async("cpauto", answer);

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
