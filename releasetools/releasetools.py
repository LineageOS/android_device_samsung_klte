# Copyright (C) 2017 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

""" Custom OTA commands for klte devices """

import common
import re
import os

def FullOTA_InstallEnd(info):
  info.script.Mount("/system")
  info.script.AppendExtra('assert(run_program("/tmp/install/bin/variant_blobs.sh") == 0);')
  info.script.Unmount("/system")
