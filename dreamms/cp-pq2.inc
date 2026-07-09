FINGERPRINTS = [[[,
    1fkbGdIayML1Ftc4M@8FKZD1PfKhT7OQC2KPAbZwF#k6hIT7ZFkDBS=Bains // CGA
    qujjuREeRhr1yWNOMzz@@vX17BWI71hH@i#DKfXEp2oCJNr#q4ED5U=Bains // EGA
    PJM4aRlRMy31mAtuczQn3Zv1BgC2o5xJtQGDr0Dqx2txLBWJuLLS5U=Bains // MCGA
    RN1n#dz0o0r2AjsIw@wNfX@1zXz3v7guRa2PI4N65#Rbbf34JT9hhT=Dickey // CGA
    EoiFaR9cTJH7DoumEzHpS979K57IP1aXG@6Ds8zWh9Myztj6JB8ABQ=Dickey // EGA
    DOAFeRrGcsYVDMbN8zvWWs39eL4d85fBFjmDyyo899FaVw3Jh9@gFQ=Dickey // MCGA
    LCKZud65g6r1ZBE8Y@LBPP@1n28cj7J1#i6PDpxiZ#AhLbL7F2VM1T=Granandez // CGA
    Ev032RoHezf1cL1bMz4MVIL9YjLF31db6piDUNLI1#3CUZL1xoFv9T=Granandez // EGA
    np2b6RCGZgL1oJ0Vkzqj61T9vB4PQ5LPdB2DyebeZ#eUHsk5uYSMVT=Granandez // MCGA
    D37ACdcs4Hv18R5A4@ySipL13zphb6#qn#OPihm2N#PywYz6EEi3tT=Jones // CGA
    6q6nSRq41p31v#DhczL8u6z9eKz0b@jmXLyKc2OLx9nn2JL@40LwxQ=Jones // EGA
    h8GluR4zKq@1cmeoAzNXe039RmmxCZ3TayaKZbglp9gUs@SZGcbDlQ=Jones // MCGA
    XWt3udpSpdP1yKjLo@Z#e7z1b8inP75rlLCPbLAwt@GRPlX48r1qVS=Simms // CGA
    EVJUeRuaIqH1C3IOYzqvoyz1BvsH79I6zSyD4m90B3V7tv3yL0TO5a=Simms // EGA
    n7UIqRQhSR71u1hXAzxbo7H1KfZzS5XTe52DVjJEZ3jubptJLpliFa=Simms // MCGA
    9qIbCdkOCxP1cqnRs@rO8Wr1IBIJX6sQoM2M2xyz5#wh6Rv7dIyQtT=Snider // CGA
    TWYz#Rt0eIP1BP#ngzMjASv1bejZD@u1mNyMkojuFzyNQdr0I77ede=Snider // EGA
    oCvLmRRzZwH1TcV@IzTIQT71oepAiZQh8juMrpu19zMRQfsp52hFJe=Snider // MCGA
    lunqCdgLt@r3VoXXE@7pdtL1l7X9P7Fo2YqPe2Jph8tlYfP7Ses4xS=Colby // CGA
    eN8duRSInW@01s7oAzwFVb@9Rf3gf1JYzFyDEmsp1@sb5Sb412RYFa=Colby // EGA
    rYE#CR7ZqDzll7Lk4z8iT8j9OSPZ45#93GuDOeiEp@9238npnfWS1a=Colby // MCGA
    8RuECdnWoE@3KQ3tw@0JHln1m6xtr7KzsaOMPyYRt#f7JgP6aU#0pQ=Taselli // CGA
    So1g#RtdSIv0V@Z2YzTSqs714LxhX1juaTOM0o25p18Kqiz3of8JNd=Taselli // EGA
    E9DpiRNXEtjlopdA8z76ltf19wZTs5i@2P6M@Bg@N1nAhJwZrrmFVd=Taselli // MCGA
]]]

script[cp]:
    code = [[[$(CRLF)
        cpactive = "";
        answer = "";

        func update()
        {
          if (!script_running(cpscript))
          {
            answer = scraper_match("BIzMfQmdI", "$$(FINGERPRINTS)");

            if (answer != "")
            {
              echo("Answer: " + answer);

              if (!prop("noautocp"))
                cpscript = script_run_async("cpauto", answer+"\r");

              if (!prop("notextcp"))
                overlay_show("cpoverlay", 1, "The correct answer is: " + answer);
            }
            else
            {
              cpactive = false;
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