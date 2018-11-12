#!/usr/bin/env python
#written by Bradley McKee
#****Make sure the wireless adapter is in monitor mode****
from scapy.all import *
import sys
import os
ap_list = []
def PacketHandler(pkt)  :
  if pkt.haslayer(Dot11)  :
    if pkt.type == 0 and pkt.subtype == 8 :
      if pkt.addr2 not in ap_list :
        f = open("wifi_list.txt","a+")
        ap_list.append(pkt.addr2)
        onewifi = "AP MAC: %s with SSID %s " %(pkt.addr2,pkt.info)
        f.write(onewifi)
        print onewifi
        f.close()

sniff(iface = "wlo1", prn = PacketHandler)

#sudo ifconfig wlo0 down
#sudo iwconfig wlo0 mode monitor
#sudo ifconfig wlo0 up
#check w/
#iwconfig
