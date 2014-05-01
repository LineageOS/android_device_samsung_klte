#!/system/bin/sh
# Copyright (c) 2012, The Linux Foundation. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#     * Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above
#       copyright notice, this list of conditions and the following
#       disclaimer in the documentation and/or other materials provided
#       with the distribution.
#     * Neither the name of The Linux Foundation nor the names of its
#       contributors may be used to endorse or promote products derived
#       from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
# WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
# ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
# BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
# WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
# OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
# IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#

# No path is set up at this point so we have to do it here.
PATH=/sbin:/system/sbin:/system/bin:/system/xbin
export PATH

# Check for images and set up symlinks
cd /firmware/image

# Get the list of files in /firmware/image
# for which sym links have to be created

fwfiles=`ls modem* adsp* wcnss* mba* tima_* venus* widevine* playread* dtcpip* securefp* skm* keymaste* sshdcpap* sec_stor* mc_v2* tzpr25*`

# Check if the links with similar names
# have been created in /system/etc/firmware

cd /system/etc/firmware
linksNeeded=0

# For everyfile in fwfiles check if
# the corresponding file exists
for fwfile in $fwfiles; do

   # if (condition) does not seem to work
   # with the android shell. Therefore
   # make do with case statements instead.
   # if a file named $fwfile is present
   # no need to create links. If the file
   # with the name $fwfile is not present
   # need to create links.

   case `ls $fwfile` in
      $fwfile)
         continue;;
      *)
         # file with $fwfile does not exist
         # need to create links
         linksNeeded=1
         break;;
   esac

done


case $linksNeeded in
   1)
      cd /firmware/image

      case `ls modem.mdt 2>/dev/null` in
         modem.mdt)
            for imgfile in modem*; do
               ln -s /firmware/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
        *)
            # trying to log here but nothing will be logged since it is
            # early in the boot process. Is there a way to log this message?
            log -p w -t PIL no modem image found;;
      esac

      case `ls adsp.mdt 2>/dev/null` in
         adsp.mdt)
            for imgfile in adsp*; do
               ln -s /firmware/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL no adsp image found;;
      esac

      case `ls wcnss.mdt 2>/dev/null` in
         wcnss.mdt)
            for imgfile in wcnss*; do
               ln -s /firmware/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL no wcnss image found;;
      esac

      case `ls mba.mdt 2>/dev/null` in
         mba.mdt)
            for imgfile in mba*; do
               ln -s /firmware/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL no mba image found;;
      esac

      case `ls venus.mdt 2>/dev/null` in
         venus.mdt)
            for imgfile in venus*; do
               ln -s /firmware/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL no venus image found;;
      esac  

      case `ls skm.mdt 2>/dev/null` in
         skm.mdt)
            for imgfile in skm*; do
               ln -s /firmware/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL no skm image found;;
      esac

      case `ls keymaste.mdt 2>/dev/null` in
         keymaste.mdt)
            rm  /system/etc/firmware/keymaste.*
            for imgfile in keymaste*; do
               ln -s /firmware/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            rm  /system/etc/firmware/keymaster.*
            ;;
         *)
            log -p w -t PIL no keymaste image found;;
      esac

      case `ls sec_stor.mdt 2>/dev/null` in
         sec_stor.mdt)
            for imgfile in sec_stor*; do
               ln -s /firmware/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL no sec_stor image found;;
      esac

      case `ls widevine.mdt 2>/dev/null` in
         widevine.mdt)
            for imgfile in widevine*; do
               ln -s /firmware/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL no widevine image found;;
      esac

      case `ls sshdcpap.mdt 2>/dev/null` in
         sshdcpap.mdt)
            for imgfile in sshdcpap*; do
               ln -s /firmware/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL no sshdcpap image found;;
      esac

      case `ls playread.mdt 2>/dev/null` in
         playread.mdt)
            for imgfile in playread*; do
               ln -s /firmware/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL no playread image found;;
      esac  

      case `ls tima_pkm.mdt 2>/dev/null` in
         tima_pkm.mdt)
            for imgfile in tima_pkm*; do
               ln -s /firmware/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL 8974 device but no tima_pkm image found;;
      esac

      case `ls tima_lkm.mdt 2>/dev/null` in
         tima_lkm.mdt)
            for imgfile in tima_lkm*; do
               ln -s /firmware/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL 8974 device but no tima_lkm image found;;
      esac

      case `ls tima_atn.mdt 2>/dev/null` in
         tima_atn.mdt)
            for imgfile in tima_atn*; do
               ln -s /firmware/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL 8974 device but no tima_atn image found;;
      esac

      case `ls dtcpip.mdt 2>/dev/null` in
         dtcpip.mdt)
            for imgfile in dtcpip*; do
               ln -s /firmware/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL 8974 device but no dtcpip image found;;
      esac

      case `ls securefp.mdt 2>/dev/null` in
         securefp.mdt)
            for imgfile in securefp*; do
               ln -s /firmware/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL 8974 device but no securefp image found;;
      esac

      case `ls mc_v2.mdt 2>/dev/null` in
         mc_v2.mdt)
            for imgfile in mc_v2*; do
               ln -s /firmware/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL 8974 device but no mc_v2 image found;;
      esac

      case `ls tima_key.mdt 2>/dev/null` in
         tima_key.mdt)
            for imgfile in tima_key*; do
               ln -s /firmware/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL 8974 device but no tima_key image found;;
      esac

      case `ls tzpr25.mdt 2>/dev/null` in
         tzpr25.mdt)
            for imgfile in tzpr25*; do
               ln -s /firmware/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL no tzpr25 image found;;
      esac
      ;;

   *)
      # Nothing to do. No links needed
      ;;
esac


# Check for images and set up symlinks
cd /firmware-modem/image

# Get the list of files in /firmware/image
# for which sym links have to be created

fwfiles=`ls modem* adsp* wcnss* mba* tima_* venus* widevine* playread* dtcpip* skm* keymaste* sshdcpap* sec_stor* mc_v2*`

# Check if the links with similar names
# have been created in /system/etc/firmware

cd /system/etc/firmware
linksNeeded=0

# For everyfile in fwfiles check if
# the corresponding file exists
for fwfile in $fwfiles; do

   # if (condition) does not seem to work
   # with the android shell. Therefore
   # make do with case statements instead.
   # if a file named $fwfile is present
   # no need to create links. If the file
   # with the name $fwfile is not present
   # need to create links.

   case `ls $fwfile` in
      $fwfile)
         continue;;
      *)
         # file with $fwfile does not exist
         # need to create links
         linksNeeded=1
         break;;
   esac

done
case $linksNeeded in
   1)
      cd /firmware-modem/image

        case `ls modem.mdt` in
         modem.mdt)
            for imgfile in modem*; do
               ln -s /firmware-modem/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
        *)
            # trying to log here but nothing will be logged since it is
            # early in the boot process. Is there a way to log this message?
            log -p w -t PIL no modem image found;;
      esac

      case `ls adsp.mdt 2>/dev/null` in
         adsp.mdt)
            for imgfile in adsp*; do
               ln -s /firmware-modem/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL no adsp image found;;
      esac

      case `ls wcnss.mdt 2>/dev/null` in
         wcnss.mdt)
            for imgfile in wcnss*; do
               ln -s /firmware-modem/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL no wcnss image found;;
      esac

      case `ls mba.mdt 2>/dev/null` in
         mba.mdt)
            for imgfile in mba*; do
               ln -s /firmware-modem/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL no mba image found;;
      esac

      case `ls venus.mdt 2>/dev/null` in
         venus.mdt)
            for imgfile in venus*; do
               ln -s /firmware-modem/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL no venus image found;;
      esac

      case `ls skm.mdt 2>/dev/null` in
         skm.mdt)
            for imgfile in skm*; do
               ln -s /firmware-modem/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL no skm image found;;
      esac

      case `ls keymaste.mdt 2>/dev/null` in
         keymaste.mdt)
            rm  /system/etc/firmware/keymaste.*
            for imgfile in keymaste*; do
               ln -s /firmware-modem/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            rm  /system/etc/firmware/keymaster.*
            ;;
         *)
            log -p w -t PIL no keymaste image found;;
      esac

      case `ls sec_stor.mdt 2>/dev/null` in
         sec_stor.mdt)
            for imgfile in sec_stor*; do
               ln -s /firmware-modem/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL no sec_stor image found;;
      esac

      case `ls widevine.mdt 2>/dev/null` in
         widevine.mdt)
            for imgfile in widevine*; do
               ln -s /firmware-modem/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL no widevine image found;;
      esac

      case `ls sshdcpap.mdt 2>/dev/null` in
         sshdcpap.mdt)
            for imgfile in sshdcpap*; do
               ln -s /firmware-modem/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL no sshdcpap image found;;
      esac

      case `ls playread.mdt 2>/dev/null` in
         playread.mdt)
            for imgfile in playread*; do
               ln -s /firmware-modem/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL no playread image found;;
      esac

      case `ls tima_pkm.mdt 2>/dev/null` in
         tima_pkm.mdt)
            for imgfile in tima_pkm*; do
               ln -s /firmware-modem/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL 8974 device but no tima_pkm image found;;
      esac

      case `ls tima_lkm.mdt 2>/dev/null` in
         tima_lkm.mdt)
            for imgfile in tima_lkm*; do
               ln -s /firmware-modem/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL 8974 device but no tima_lkm image found;;
      esac

      case `ls tima_atn.mdt 2>/dev/null` in
         tima_atn.mdt)
            for imgfile in tima_atn*; do
               ln -s /firmware-modem/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL 8974 device but no tima_atn image found;;
      esac

      case `ls dtcpip.mdt 2>/dev/null` in
         dtcpip.mdt)
            for imgfile in dtcpip*; do
               ln -s /firmware-modem/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL 8974 device but no dtcpip image found;;
      esac

      case `ls mc_v2.mdt 2>/dev/null` in
         mc_v2.mdt)
            for imgfile in mc_v2*; do
               ln -s /firmware-modem/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            break;;
         *)
            log -p w -t PIL 8974 device but no mc_v2 image found;;
      esac

      case `ls tima_key.mdt 2>/dev/null` in
         tima_key.mdt)
            for imgfile in tima_key*; do
               ln -s /firmware-modem/image/$imgfile /system/etc/firmware/$imgfile 2>/dev/null
            done
            ;;
         *)
            log -p w -t PIL 8974 device but no tima_key image found;;
      esac

      ;;

   *)
      # Nothing to do. No links needed
      ;;
esac


cd /
