# rsp-final-project
RSP Final Project

## Installation
- `mkdir -p rsp_fp_ws/src`
- `cd rsp_fp_ws/src`
- `git clone --recurse-submodules git@github.com:jdcast/rsp-final-project.git`

## Updating after commit: https://github.com/jdcast/rsp-final-project/commit/a74f598e87c174add4e3216217bd5e41983b91d4
- `git pull`
- `git submodule update --init --recursive`

## Workflow
- `git checkout <branch_name>`
- `<do work>`
- `git add -A`
- `git commit -am "<descriptive commit message beginning with action verb>"`
- `git push`
- `form Pull Request (PR) in github`
- `await others to review`
- `merge PR into main`
- if further work on <branch_name> needs to be done after merging its PR into `main`: (let's not use `git rebase` to save possible headaches...https://stackoverflow.com/questions/3876977/update-git-branches-from-master)
  - `git checkout main`
  - `git pull` # update local main from remote main
  - `git checkout feature/<branch_name>`
  - `git merge master` # solve merge conflicts if you have
  - `git push`
