
for i in $(get_instance_by_service shoubai-gr-tucheng.SUPERPAGE.bj); do ssh -o "StrictHostKeyChecking no" $i "grep call_generator /home/work/shoubai-gr/log/gr.log.wf " ; done > /tmp/22 &

