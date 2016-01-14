var isActive=0;
var sessionMode=1;
var breakMode=0;
var isPaused=1;//dont get confused
var isSessionPaused=0;
var isBreakPaused=0;
var breakTime={min:5,second:0};
var sessionTime={min:25,second:0};
var csessiontime={min:25,second:0};
var cbreaktime={min:5,second:0};
var timer=0;
var change=0;

function stringify(num)
{
	if(num<10)
		return('0'.concat(num.toString()));
	else
		return(num.toString());
}
function timeFormat(str1,str2)
{
	return(str1.concat(':').concat(str2));
}
function printClockTime(type)  // this function is just for printing the session time in the specified format of MM:SS. Nothing fancy here.
{
    var sessionmin_str="",sessionsec_str="",breakmin_str="",breaksec_str="";
    sessionmin_str=stringify(csessiontime['min']);
    sessionsec_str=stringify(csessiontime['second']);
	breakmin_str=stringify(cbreaktime['min']);
	breaksec_str=stringify(cbreaktime['second']);
	if(isActive==0)
		document.getElementById('time').innerHTML=timeFormat(sessionmin_str,sessionsec_str);
	else
	{
		if(sessionMode)
			document.getElementById('time').innerHTML=timeFormat(sessionmin_str,sessionsec_str);
		else if(breakMode)
			document.getElementById('time').innerHTML=timeFormat(breakmin_str,breaksec_str);
	}		
}
function printSessionTime()
{
	var sessionmin_str="",sessionsec_str="";
	sessionmin_str=stringify(sessionTime['min']);
    sessionsec_str=stringify(sessionTime['second']);
	document.getElementById('session_length').innerHTML=sessionmin_str.concat(':').concat(sessionsec_str);
}
function printBreakTime()
{
	var breakmin_str="",breaksec_str="";
	breakmin_str=stringify(breakTime['min']);
    breaksec_str=stringify(breakTime['second']);
	document.getElementById('break_length').innerHTML=breakmin_str.concat(':').concat(breaksec_str);
}
	
function incSessionTime()
{
	if(isPaused)
	{
    	sessionTime['min']++;
		csessiontime['min']=sessionTime['min'];
		csessiontime['second']=sessionTime['second'];
     	printClockTime();
		printSessionTime();
	}
}

function decSessionTime()
{
	if(isPaused)
	{
  		if(sessionTime['min']>1)
		{
  			sessionTime['min']--;
			csessiontime['min']=sessionTime['min'];
			csessiontime['second']=sessionTime['second'];
		}
  		printClockTime();
  		printSessionTime();
	}
}
function incBreakTime()
{
	if(isPaused)
	{
    	breakTime['min']++;
		cbreaktime['min']=breakTime['min'];
		cbreaktime['second']=breakTime['second'];
     	printClockTime();
		printBreakTime();
	}
}
function decBreakTime()
{
	if(isPaused)
	{
		if(breakTime['min']>1)
		{
    		breakTime['min']--;
			cbreaktime['min']=breakTime['min'];
			cbreaktime['second']=breakTime['second'];
		}
     	printClockTime();
		printBreakTime();
	}
}

	
function resetClicked()
{
	if(!isPaused)
		clearInterval(timer);
	sessionTime['min']=25;
	sessionTime['second']=0;
	breakTime['min']=5;
	breakTime['second']=0;
	csessiontime={min:25,second:0};
	cbreaktime={min:5,second:0};
	printClockTime();
	printBreakTime();
	printSessionTime();
	isActive=0;
	sessionMode=1;
	breakMode=0;
	isPaused=1;//dont get confused
    isSessionPaused=0;
	isBreakPaused=0;	
	document.getElementById('title').innerHTML="TIMER";
	document.getElementById('time').style.background="#ddd";
	document.getElementById('time').style.color="#333";
}
	
		
document.getElementById('session_plus').onclick=function incSession(){incSessionTime();};
document.getElementById('session_minus').onclick=function decSession(){decSessionTime();};
document.getElementById('break_minus').onclick=function decBreak(){decBreakTime();};
document.getElementById('break_plus').onclick=function incBreak(){incBreakTime();};
document.getElementById('time').onclick=function clock(){
		isActive=1;
		if(isPaused)
			isPaused=0;
		else
		{
			isPaused=1;
			clearInterval(timer);
		}
	if(isPaused && sessionMode)
	{
		isSessionPaused=1;
	}
	else if(isPaused && breakMode)
		isBreakPaused=1;
	else if(isSessionPaused)
		isSessionPaused=0;
	else if(isBreakPaused)
		isBreakPaused=0;
	 if(isPaused==0)	
	 	timer=setInterval(clockClicked,1000);
		function clockClicked()
		{
			document.getElementById('time').style.color="black";
			if(sessionMode==1)
				document.getElementById('title').innerHTML="WORK";
			else if(breakMode==1)
				document.getElementById('title').innerHTML="RELAX";
			if(change==0)
			{
				document.getElementById('time').style.background="white";
				change=1;
			}
			else if(change==1)
			{
				document.getElementById('time').style.background="#ddd";
				change=0;
			}
				
			if(!isSessionPaused && sessionMode)
			{
				if(csessiontime['second']==0)
				{
					csessiontime['second']=59;
					csessiontime['min']--;
				}
				else
					csessiontime['second']--;
				printClockTime();
				if(csessiontime['min']<=0 && csessiontime['second']==0)
				{
					sessionMode=0;
					breakMode=1;
					isSessionPaused=0;
				}
			}
			else if(isSessionPaused)
			{
				clearInterval(timer);
			}
			else if(!isBreakPaused && breakMode)
			{
				if(cbreaktime['second']==0)
				{
					cbreaktime['second']=59;
					cbreaktime['min']--;
				}
				else
					cbreaktime['second']--;
				printClockTime();
				if(cbreaktime['min']<=0 && cbreaktime['second']==0)
				{
					breakMode=0;
					isActive=0;
					clearInterval(timer);
				}
			}
			else if(isBreakPaused)
			{
				clearInterval(timer);
			}
		}
};
document.getElementById('reset').onclick=function clock(){ resetClicked();};
document.getElementById('title').innerHTML="TIMER";

