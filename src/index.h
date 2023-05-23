const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<head>
  <title>ESP8266 Relay Board</title>
  <script>
    var State1;
    var State2;
    var State3;
    var State4;
    var State5;
    var State6;
    var State7;
    var State8;
    var State9;
    var State10;
    var State11;
    var State12;
    var State13;
    var State14;
    var State15;
    var State16;
    function DisplayCurrentTime() {
      var dt = new Date();
      var weekday = new Array(7);
      weekday[0] = "Sunday";
      weekday[1] = "Monday";
      weekday[2] = "Tuesday";
      weekday[3] = "Wednesday";
      weekday[4] = "Thursday";
      weekday[5] = "Friday";
      weekday[6] = "Saturday";
      var dow = weekday[dt.getDay()];
      document.getElementById("datetime").innerHTML = (dow) + " " + (dt.toLocaleString());
      setTimeout('DisplayCurrentTime()', 1000);
    };
    function GetState() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          State1 = this.responseXML.getElementsByTagName("analog")[0].childNodes[0].nodeValue;
          State2 = this.responseXML.getElementsByTagName("analog")[1].childNodes[0].nodeValue;
          State3 = this.responseXML.getElementsByTagName("analog")[2].childNodes[0].nodeValue;
          State4 = this.responseXML.getElementsByTagName("analog")[3].childNodes[0].nodeValue;
          State5 = this.responseXML.getElementsByTagName("analog")[4].childNodes[0].nodeValue;
          State6 = this.responseXML.getElementsByTagName("analog")[5].childNodes[0].nodeValue;
          State7 = this.responseXML.getElementsByTagName("analog")[6].childNodes[0].nodeValue;
          State8 = this.responseXML.getElementsByTagName("analog")[7].childNodes[0].nodeValue;
          State9 = this.responseXML.getElementsByTagName("analog")[8].childNodes[0].nodeValue;
          State10 = this.responseXML.getElementsByTagName("analog")[9].childNodes[0].nodeValue;
          State11 = this.responseXML.getElementsByTagName("analog")[10].childNodes[0].nodeValue;
          State12 = this.responseXML.getElementsByTagName("analog")[11].childNodes[0].nodeValue;
          State13 = this.responseXML.getElementsByTagName("analog")[12].childNodes[0].nodeValue;
          State14 = this.responseXML.getElementsByTagName("analog")[13].childNodes[0].nodeValue;
          State15 = this.responseXML.getElementsByTagName("analog")[14].childNodes[0].nodeValue;
          State16 = this.responseXML.getElementsByTagName("analog")[15].childNodes[0].nodeValue;
        }
        if (State1 != 0) {
          var codeBlock1 = '<button type="submit" class="button-on">Relay 1 On</button>';
          document.getElementById("statled1").innerHTML = codeBlock1;
        } else {
          var codeBlock1 = '<button type="submit" class="button-off">Relay 1 Off</button>';
          document.getElementById("statled1").innerHTML = codeBlock1;
        }
        if (State2 != 0) {
          var codeBlock2 = '<button type="submit" class="button-on">Relay 2 On</button>';
          document.getElementById("statled2").innerHTML = codeBlock2;
        } else {
          var codeBlock2 = '<button type="submit" class="button-off">Relay 2 Off</button>';
          document.getElementById("statled2").innerHTML = codeBlock2;
        }
        if (State3 != 0) {
          var codeBlock3 = '<button type="submit" class="button-on">Relay 3 On</button>';
          document.getElementById("statled3").innerHTML = codeBlock3;
        } else {
          var codeBlock3 = '<button type="submit" class="button-off">Relay 3 Off</button>';
          document.getElementById("statled3").innerHTML = codeBlock3;
        }
        if (State4 != 0) {
          var codeBlock4 = '<button type="submit" class="button-on">Relay 4 On</button>';
          document.getElementById("statled4").innerHTML = codeBlock4;
        } else {
          var codeBlock4 = '<button type="submit" class="button-off">Relay 4 Off</button>';
          document.getElementById("statled4").innerHTML = codeBlock4;
        }
        if (State5 != 0) {
          var codeBlock5 = '<button type="submit" class="button-on">Relay 5 On</button>';
          document.getElementById("statled5").innerHTML = codeBlock5;
        } else {
          var codeBlock5 = '<button type="submit" class="button-off">Relay 5 Off</button>';
          document.getElementById("statled5").innerHTML = codeBlock5;
        }
        if (State6 != 0) {
          var codeBlock6 = '<button type="submit" class="button-on">Relay 6 Off</button>';
          document.getElementById("statled6").innerHTML = codeBlock6;
        } else {
          var codeBlock6 = '<button type="submit" class="button-off">Relay 6 Off</button>';
          document.getElementById("statled6").innerHTML = codeBlock6;
        }
        if (State7 != 0) {
          var codeBlock7 = '<button type="submit" class="button-on">Relay 7 On</button>';
          document.getElementById("statled7").innerHTML = codeBlock7;
        } else {
          var codeBlock7 = '<button type="submit" class="button-off">Relay 7 Off</button>';
          document.getElementById("statled7").innerHTML = codeBlock7;
        }
        if (State8 != 0) {
          var codeBlock8 = '<button type="submit" class="button-on">Relay 8 On</button>';
          document.getElementById("statled8").innerHTML = codeBlock8;
        } else {
          var codeBlock8 = '<button type="submit" class="button-off">Relay 8 Off</button>';
          document.getElementById("statled8").innerHTML = codeBlock8;
        }
        if (State9 != 0) {
          var codeBlock9 = '<button type="submit" class="button-on">Relay 9 On</button>';
          document.getElementById("statled9").innerHTML = codeBlock9;
        } else {
          var codeBlock9 = '<button type="submit" class="button-off">Relay 9 Off</button>';
          document.getElementById("statled9").innerHTML = codeBlock9;
        }
        if (State10 != 0) {
          var codeBlock10 = '<button type="submit" class="button-on">Relay 10 On</button>';
          document.getElementById("statled10").innerHTML = codeBlock10;
        } else {
          var codeBlock10 = '<button type="submit" class="button-off">Relay 10 Off</button>';
          document.getElementById("statled10").innerHTML = codeBlock10;
        }
        if (State11 != 0) {
          var codeBlock11 = '<button type="submit" class="button-on">Relay 11 On</button>';
          document.getElementById("statled11").innerHTML = codeBlock11;
        } else {
          var codeBlock11 = '<button type="submit" class="button-off">Relay 11 Off</button>';
          document.getElementById("statled11").innerHTML = codeBlock11;
        }
        if (State12 != 0) {
          var codeBlock12 = '<button type="submit" class="button-on">Relay 12 On</button>';
          document.getElementById("statled12").innerHTML = codeBlock12;
        } else {
          var codeBlock12 = '<button type="submit" class="button-off">Relay 12 Off</button>';
          document.getElementById("statled12").innerHTML = codeBlock12;
        }
        if (State13 != 0) {
          var codeBlock13 = '<button type="submit" class="button-on">Relay 13 On</button>';
          document.getElementById("statled13").innerHTML = codeBlock13;
        } else {
          var codeBlock13 = '<button type="submit" class="button-off">Relay 13 Off</button>';
          document.getElementById("statled13").innerHTML = codeBlock13;
        }
        if (State14 != 0) {
          var codeBlock14 = '<button type="submit" class="button-on">Relay 14 On</button>';
          document.getElementById("statled14").innerHTML = codeBlock14;
        } else {
          var codeBlock14 = '<button type="submit" class="button-off">Relay 14 Off</button>';
          document.getElementById("statled14").innerHTML = codeBlock14;
        }
        if (State15 != 0) {
          var codeBlock15 = '<button type="submit" class="button-on">Relay 15 On</button>';
          document.getElementById("statled15").innerHTML = codeBlock15;
        } else {
          var codeBlock15 = '<button type="submit" class="button-off">Relay 15 Off</button>';
          document.getElementById("statled15").innerHTML = codeBlock15;
        }
        if (State16 != 0) {
          var codeBlock16 = '<button type="submit" class="button-on">Relay 16 On</button>';
          document.getElementById("statled16").innerHTML = codeBlock16;
        } else {
          var codeBlock16 = '<button type="submit" class="button-off">Relay 16 Off</button>';
          document.getElementById("statled16").innerHTML = codeBlock16;
        }
      }
      xhttp.open("GET", "redstate", true);
      xhttp.send();
      setTimeout('GetState()', 1000);
    };
    document.addEventListener('DOMContentLoaded', function () {
      DisplayCurrentTime(), GetState();
    }, false);
  </script>
  <style>
    body {
      text-align: center;
      background-color: #ffaaaa;
    }

    /* Full-width input fields */
    input[type=text],
    input[type=password] {
      width: 100%;
      padding: 12px 20px;
      margin: 8px 0;
      display: inline-block;
      border: 1px solid #ccc;
      box-sizing: border-box;
    }

    .container {
      padding: 16px;
    }

    span.psw {
      float: right;
      padding-top: 16px;
    }

    /* The Modal (background) */
    .modal {
      display: none;
      /* Hidden by default */
      position: fixed;
      /* Stay in place */
      z-index: 1;
      /* Sit on top */
      left: 0;
      top: 0;
      width: 100%;
      /* Full width */
      height: 100%;
      /* Full height */
      overflow: auto;
      /* Enable scroll if needed */
      background-color: rgb(0, 0, 0);
      /* Fallback color */
      background-color: rgba(0, 0, 0, 0.4);
      /* Black w/ opacity */
      padding-top: 60px;
    }

    /* Set a style for all buttons */
    button {
      padding: 5px 5px 5px 5px;
      text-shadow: 2px 2px #000000;
      width: 100%;
      border: #fbfb00 solid 3px;
      background-color: #0000ff;
      color: white;
      font-size: 15px;
      padding-bottom: 5px;
      font-weight: 600;
      -moz-border-radius: 10px;
      -webkit-border-radius: 10px;
    }

    button:hover {
      text-shadow: 2px 2px #ff0000;
      opacity: 0.8;
    }

    .button-on {
      padding: 5px 5px 5px 5px;
      text-shadow: 2px 2px #ffffff;
      width: 80%;
      border: #fbfb00 solid 3px;
      background-color: #00ff00;
      color: #000000;
      font-size: 15px;
      padding-bottom: 5px;
      font-weight: 700;
      -moz-border-radius: 12px;
      -webkit-border-radius: 12px;
    }

    .button-on:hover {
      text-shadow: 2px 2px #444400;
      opacity: 0.8;
    }

    .button-on-latch {
      padding: 5px 5px 5px 5px;
      text-shadow: 2px 2px #ffffff;
      width: 80%;
      border: #fbfb00 solid 3px;
      background-color: #00FF00;
      color: #000000;
      font-size: 15px;
      padding-bottom: 5px;
      font-weight: 700;
      animation: blinkingBackground 1s infinite;
      -moz-border-radius: 12px;
      -webkit-border-radius: 12px;
    }

    @keyframes blinkingBackground {
      0% {
        background-color: #008000;
      }

      50% {
        background-color: #32CD32;
      }

      100% {
        background-color: #00FF00;
      }
    }

    .button-on-latch:hover {
      text-shadow: 2px 2px #444400;
      opacity: 0.8;
    }

    .button-off {
      padding: 5px 5px 5px 5px;
      text-shadow: 2px 2px #000000;
      width: 80%;
      border: #fbfb00 solid 3px;
      background-color: #ff0000;
      color: #ffffff;
      font-size: 15px;
      padding-bottom: 5px;
      font-weight: 700;
      -moz-border-radius: 12px;
      -webkit-border-radius: 12px;
    }

    .button-off:hover {
      text-shadow: 2px 2px #ffffff;
      opacity: 0.8;
    }

    .button-home {
      background-color: #BA55D3;
    }

    /* Modal Content/Box */
    .modal-content {
      background-color: #fefefe;
      margin: 5% auto 15% auto;
      /* 5% from the top, 15% from the bottom and centered */
      border: 1px solid #888;
      width: 40%;
      /* Could be more or less, depending on screen size */
    }

    /* Add Zoom Animation */
    .animate {
      -webkit-animation: animatezoom 0.6s;
      animation: animatezoom 0.6s
    }

    @-webkit-keyframes animatezoom {
      from {
        -webkit-transform: scale(0)
      }

      to {
        -webkit-transform: scale(1)
      }
    }

    @keyframes animatezoom {
      from {
        transform: scale(0)
      }

      to {
        transform: scale(1)
      }
    }

    /* Change styles for span and cancel button on extra small screens */
    @media screen and (max-width: 300px) {
      span.psw {
        display: block;
        float: none;
      }

      .cancelbtn {
        width: 100%;
      }
    }

    .data-input {
      text-align: center;
      background-color: #bbbbff;
      font-size: 15px;
      color: red;
      border: 5px solid #444444;
      -moz-border-radius: 7px;
      -webkit-border-radius: 7px;
    }

    table {
      text-align: center;
      border: 2px solid #ff00ff;
      background-color: #ffffff;
      width: 100%;
      color: #0000ff;
      -moz-border-radius: 7px;
      -webkit-border-radius: 7px;
    }

    td {
      border: 2px solid #00ffff;
      background-color: #111111;
      padding: 5px;
      -moz-border-radius: 9px;
      -webkit-border-radius: 9px;
    }

    .dtime {
      padding: 5px 5px 5px 5px;
      width: 100%;
      border: #fbfb00 solid 3px;
      background-color: red;
      color: #ffffff;
      font-size: 15px;
      padding-bottom: 5px;
      font-weight: 700;
      -moz-border-radius: 7px;
      -webkit-border-radius: 7px;
    }
  </style>
</head>

<body>
  <table>
    <tr>
      <td style='width:40%'>
        <form action="/LED1" method="POST">
          <span id="statled1"></span>
        </form>
      </td>
      <td style='width:40%'>
        <form action="/LED2" method="POST">
          <span id="statled2"></span>
        </form>
      </td>
    </tr>
    <tr>
      <td style='width:40%'>
        <form action="/LED3" method="POST">
          <span id="statled3"></span>
        </form>
      </td>
      <td style='width:40%'>
        <form action="/LED4" method="POST">
          <span id="statled4"></span>
        </form>
      </td>
    </tr>
    <tr>
      <td style='width:40%'>
        <form action="/LED5" method="POST">
          <span id="statled5"></span>
        </form>
      </td>
      <td style='width:40%'>
        <form action="/LED6" method="POST">
          <span id="statled6"></span>
        </form>
      </td>
    </tr>
    <tr>
      <td style='width:40%'>
        <form action="/LED7" method="POST">
          <span id="statled7"></span>
        </form>
      </td>
      <td style='width:40%'>
        <form action="/LED8" method="POST">
          <span id="statled8"></span>
        </form>
      </td>
    </tr>
    <tr>
      <td style='width:40%'>
        <form action="/LED9" method="POST">
          <span id="statled9"></span>
        </form>
      </td>
      <td style='width:40%'>
        <form action="/LED10" method="POST">
          <span id="statled10"></span>
        </form>
      </td>
    </tr>
    <tr>
      <td style='width:40%'>
        <form action="/LED11" method="POST">
          <span id="statled11"></span>
        </form>
      </td>
      <td style='width:40%'>
        <form action="/LED12" method="POST">
          <span id="statled12"></span>
        </form>
      </td>
    </tr>
    <tr>
      <td style='width:40%'>
        <form action="/LED13" method="POST">
          <span id="statled13"></span>
        </form>
      </td>
      <td style='width:40%'>
        <form action="/LED14" method="POST">
          <span id="statled14"></span>
        </form>
      </td>
    </tr>
    <tr>
      <td style='width:40%'>
        <form action="/LED15" method="POST">
          <span id="statled15"></span>
        </form>
      </td>
      <td style='width:40%'>
        <form action="/LED16" method="POST">
          <span id="statled16"></span>
        </form>
      </td>
    </tr>
    <tr>
      <td style='width:40%'>
        <form action="/" method="POST">
          <button type="submit" class="button-home">Home</button>
        </form>
      </td>
      <td style='width:40%'>
        <form action="/alloff" method="POST">
          <button type="submit" class="button">All Relays OFF</button>
        </form>
      </td>
    </tr>
    <tr>
      <td style='width:40%'>
        <b class="dtime"><span id="datetime"></span></b>
      </td>
      <td style='width:40%'>
        <form action="/restesp" method="POST">
          <button type="submit" name="rerset" class="button">Restart ESP</button>
        </form>
      </td>
    </tr>
  </table>
</body>

</html>
)=====";
