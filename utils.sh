
for i in $(get_instance_by_service shoubai-gr-tucheng.SUPERPAGE.bj); do ssh -o "StrictHostKeyChecking no" $i "grep call_generator /home/work/shoubai-gr/log/gr.log.wf " ; done > /tmp/22 &

# git 技巧

## 

## 查看历史commit_id的改动
### 首先使用git blame 查看对应的代码改动负责人、改动时间，改动的commit_id
### 然后通过 git diff ${commit_id}^! 查看对应改动diff
git diff ${commit_id}^!


# grep 命令

## 或关系
grep sample_info image-single-list-dict.log | grep -E 'vertical_type:16|vertical_type:11' | wc  -l

