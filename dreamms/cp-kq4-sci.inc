$(include cp-kq4-answers.inc)

charset[scifont]:
    height = 9
    char[#]: bits = 480`fc0`480`fc0`480
    char[']: bits = c00`000`c00
    char[(]: bits = 380`440`820
    char[)]: bits = 820`440`380
    char[,]: bits = 010`020
    char[.]: bits = 020
    char[1]: bits = 420`fe0`020
    char[2]: bits = 460`8a0`920`620
    char[3]: bits = 440`920`920`6c0
    char[4]: bits = 180`680`880`fe0`080
    char[5]: bits = e40`a20`a20`9c0
    char[6]: bits = 7c0`920`920`0c0
    char[7]: bits = 800`9e0`a00`c00
    char[8]: bits = 6c0`920`920`6c0
    char[9]: bits = 600`920`920`7c0
    char[:]: bits = 240
    char[?]: bits = 400`9a0`600
    char[A]: bits = 7e0`900`900`7e0
    char[B]: bits = fe0`920`920`6c0
    char[D]: bits = fe0`820`820`7c0
    char[E]: bits = fe0`920`920`820
    char[F]: bits = fe0`900`900`800
    char[G]: bits = 7c0`820`820`920`5c0
    char[H]: bits = fe0`100`100`100`fe0
    char[I]: bits = 820`fe0`820
    char[K]: bits = fe0`100`280`440`820
    char[L]: bits = fe0`020`020`020
    char[M]: bits = fe0`400`300`400`fe0
    char[N]: bits = fe0`200`100`080`fe0
    char[O]: bits = 7c0`820`820`7c0
    char[P]: bits = fe0`900`900`600
    char[Q]: bits = 7c0`820`820`7d0
    char[R]: bits = fe0`900`900`6e0
    char[S]: bits = 640`920`920`4c0
    char[T]: bits = 800`800`fe0`800`800
    char[U]: bits = fc0`020`020`fc0
    char[V]: bits = f80`040`020`040`f80
    char[W]: bits = fc0`020`0c0`020`fc0
    char[Y]: bits = e00`100`0e0`100`e00
    char[a]: bits = 040`2a0`2a0`1c0`020
    char[b]: bits = fc0`220`220`1c0
    char[c]: bits = 1c0`220`220`140
    char[d]: bits = 1c0`220`220`fc0
    char[e]: bits = 1c0`2a0`2a0`1a0
    char[f]: bits = 100`7e0`900`800
    char[g]: bits = 1c0`228`228`1f0
    char[h]: bits = fe0`200`200`1e0
    char[i]: bits = be0
    char[j]: bits = 010`be0
    char[k]: bits = fe0`080`140`220
    char[l]: bits = fe0
    char[m]: bits = 3e0`200`200`1e0`200`200`1e0
    char[n]: bits = 3e0`100`200`1e0
    char[o]: bits = 1c0`220`220`1c0
    char[p]: bits = 3f0`240`240`180
    char[q]: bits = 180`240`240`3f0
    char[r]: bits = 3e0`100`200`200
    char[s]: bits = 120`2a0`2a0`240
    char[t]: bits = 200`fc0`220
    char[u]: bits = 3c0`020`020`3c0`020
    char[v]: bits = 380`040`020`040`380
    char[w]: bits = 3c0`020`3c0`020`3c0
    char[x]: bits = 220`140`080`140`220
    char[y]: bits = 380`050`050`3e0
end

script[cp]:
    code = [[[$(CRLF)
        func update()
        {
          if (!script_running(cpscript))
          {
            str = scraper_string("BAAGF@@I9", "scifont", 0);

            if (str == "Inordertoverifyyourlegalownership,pleaseuseyour")
            {
              question = scraper_string("FAAOu@@RmAARm@@UfAAUf@@XXAAXX@@aPAAaP@@dI", "scifont", 0);
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
