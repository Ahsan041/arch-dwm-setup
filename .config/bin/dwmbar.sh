#!/usr/bin/bash

interval=0

## Cpu Info
cpu_info() {
	cpu_load=$(grep -o "^[^ ]*" /proc/loadavg)

	printf "^c#3b414d^ ^b#7ec7a2^ CPU"
	printf "^c#abb2bf^ ^b#353b45^ $cpu_load"
}

## Memory
memory() {
	printf "^c#C678DD^^b#1e222a^   $(free -h | awk '/^Mem/ { print $3 }' | sed s/i//g) "
}

## Wi-fi
wlan() {
	case "$(cat /sys/class/net/w*/operstate 2>/dev/null)" in
		up) printf "^c#3b414d^^b#7aa2f7^  ^d^%s" " ^c#7aa2f7^Connected " ;;
		down) printf "^c#3b414d^^static const char black[]           = "#21222c";
static const char black[]       	= "#1e222a";
static const char gray2[]       	= "#2e323a"; // unfocused window border
static const char gray3[]       	= "#545862";
static const char gray4[]       	= "#6d8dad";
static const char blue[]        	= "#61afef";  // focused window border
static const char green[]       	= "#7EC7A2";
static const char red[]         	= "#e06c75";
static const char orange[]      	= "#caaa6a";
static const char yellow[]      	= "#EBCB8B";
static const char pink[]        	= "#c678dd";
static const char col_borderbar[]  	= "#1e222a"; // inner border#E06C75^
睊 ^d^%s" " ^c#E06C75^Disconnected " ;;
	esac
}

## Time
clock() {
	printf "^c#1e222a^^b#668ee3^  "
	printf "^c#1e222a^^b#7aa2f7^ $(date '+%I:%M %p') "
}

## 
date1() {
    printf "^c#1e222a^^b#f8f8f2^ $(date '+%a, %B %d') "
}

## System Update
updates() {
	updates=$(checkupdates | wc -l)

	if [ -z "$updates" ]; then
		printf "^c#98C379^  Updated"
	else
		printf "^c#98C379^  $updates"" updates"
	fi
}



## Main
while true; do
  [ "$interval" == 0 ] || [ $(("$interval" % 3600)) == 0 ] && updates=$(updates)
  interval=$((interval + 1))

  sleep 1 && xsetroot -name "$(cpu_info) $(memory) $(wlan) $(clock) $(date1)"
done
