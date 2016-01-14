$(document).ready(function() {
  var stintrval;
  var brkInterval;
  var isRunning = false;
  var breakRunning = false;
  var breakD;
  var breakD1;

  function durationlength() {
    var timedur = document.getElementsByTagName("strong")[1];
    var timeD = timedur.innerHTML;
    timeD = parseInt(timeD) + 1;
    if (timeD < 10) {
      timeD = "0" + timeD;
    }
    console.log("timedur is:", timeD);
    timeD1 = timeD + ":" + "00";
    document.getElementsByTagName("strong")[1].innerHTML = timeD;
    document.getElementById("tmr").innerHTML = timeD1;
      }

  function durlength() {
    var timedur = document.getElementsByTagName("strong")[1];
    var timeD = timedur.innerHTML;
    timeD = parseInt(timeD);
    if (timeD == 1) {
      alert("duration cannot be less than 1");
    } else {
      var timeD1 = timeD - 1;
      if (timeD1 < 10) {
        timeD1 = "0" + timeD1;
      }
      console.log("timedur is:", timeD1);
      var timeD2 = timeD1 + ":" + "00";
      console.log("timeD2 is:", timeD2);
      document.getElementsByTagName("strong")[1].innerHTML = timeD1;
      document.getElementById("tmr").innerHTML = timeD2;
      
    }

  }

  function breaklength() {
    var brklength = document.getElementsByTagName("strong")[0];
    var brk1 = brklength.innerHTML;
    console.log("brk1 is:", brk1);
    var brk2 = parseInt(brk1) + 1;
    console.log("break length is:", brk2);
    document.getElementsByTagName("strong")[0].innerHTML = brk2;
    $("#btnb2").show();
  }

  function brklength() {
    var brklength = document.getElementsByTagName("strong")[0];
    var brk1 = brklength.innerHTML;
    console.log("brk1 is:", brk1);

    var brk2 = parseInt(brk1);
    if (brk2 == 1) {
      $("#btnb2").hide();
    } else {
      var brk3 = brk2 - 1;
      console.log("break length is:", brk3);
      document.getElementsByTagName("strong")[0].innerHTML = brk3;

    }

  }

  function timer() {
    isRunning = true;
    var time1 = document.getElementById("tmr");
    time2 = time1.innerHTML;
    console.log("time2 is:", time2);
    times2 = time2.split(":");
    console.log("times2 is:", times2);
    time3 = parseInt(times2[0]) * 60;
    console.log("time3 is:", time3);
    times3 = parseInt(times2[1]);
    console.log("times3 is:", times3);
    times4 = (time3 + times3);
    console.log("times4 is:", times4);
    if (times4 == 0) {
      timez = "00" + ":" + "00";
      document.getElementById("tmr").innerHTML = timez;
      $("#work").text("Break Time Begins");
      clearInterval(stintrval);
      breakD = document.getElementsByTagName("strong")[0].innerHTML
      breakD1 = parseInt(breakD) * 60000;
      brkInterval = setInterval(brkTime, 1000);
      //Play sound
      var wav = 'http://s1download-universal-soundbank.com/mp3/sounds/2153.mp3';
      var audio = new Audio(wav);
			audio.play();
    } else {
      time4 = times4 - 1;
      console.log("time4 is:", time4);
      time5 = (time4 / 60).toFixed(2);
      console.log("time5 is:", time5);
      //times5=time5.toString();
      //console.log("times5 is:",times5);
      time6 = time5.split(".");
      console.log("time6 is:", time6);
      time7 = time6[0];
      if (time7 < 10) {
        time7 = "0" + time7;
      }
      time8 = time6[1];
      console.log("time8 is:", time8);
      times8 = time8 * 60 / 100;
      time9 = Math.round(times8);
      if (time9 < 10) {
        time9 = "0" + time9;
      }
      console.log("time9 is:", time9);
      time9Final = time7.toString() + ":" + time9.toString();
      console.log("time9Final is:", time9Final);
      document.getElementById("tmr").innerHTML = time9Final;
      $("#work").text("Work Time Begins");

    }

  }

  function pause() {
    isRunning = false;
    clearInterval(stintrval);
    $("#btnst").show();
  }

  function reset() {
    if (breakRunning == true) {
      clearInterval(brkInterval);
      breakRunning = false;
    } else {
      clearInterval(stintrval);
      isRunning = false;
    }

    var timedur = document.getElementsByTagName("strong")[1].innerHTML;
    document.getElementById("tmr").innerHTML = timedur + ":" + "00";
    $("#work").text("Is it work time or break time?");
    $("#btnst").show();
  }

  function chkRunning() {
    if (isRunning === false) {
      stintrval = setInterval(timer, 1000);
      $("#btnst").hide();
    } else {
      alert("timer is already running");
    }
  }

  function brkTime() {
    isRunning = false;
    breakRunning = true;
    breakD1 = breakD1 - 1000;
    console.log("break after -1000 is:", breakD1);
    $("#work").text("Relax! it's break time!");
    if (breakD1 == 0) {
      $("#work").text("Break is over!");
      clearInterval(brkInterval);
      breakRunning = false;
      reset();
      chkRunning();
    }
  }

  $("#btnd1").click(durationlength);
  $("#btnd2").click(durlength);
  $("#btnb1").click(breaklength);
  $("#btnb2").click(brklength);
  $("#tmr").click(chkRunning);
  $("#btnps").click(pause);
  $("#btnst").click(chkRunning);
  $("#btrst").click(reset);
});
