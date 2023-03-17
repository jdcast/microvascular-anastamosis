# rsp-final-project
RSP Final Project

## Installation
- `mkdir -p rsp_fp_ws/src`
- `cd rsp_fp_ws/src`
- `git clone git@github.com:jdcast/rsp-final-project.git`

## Workflow
- `git checkout <branch_name>`
- `<do work>`
- `git add -A`
- `git commit -am "<descriptive commit message beginning with action verb>"`
- `git push`
- `form Pull Request (PR) in github`
- `await others to review`
- `merge PR into main`
- if further work on <branch_name> needs to be done after merging its PR into `main`: (let's not do merging/rebasing to save possible headaches...)
  - cut new branch from `main`: 
  - `git checkout main`
  - `git checkout -B features/<new_branch_name>`
