# rsp-final-project
RSP Final Project

## Installation
- `mkdir -p rsp_fp_ws/src`
- `cd rsp_fp_ws/src`
- `git clone --recurse-submodules git@github.com:jdcast/rsp-final-project.git`
- Build Orocos toolchain by itself 
  - colcon build --packages-select orocos_toolchain
  - source install/setup.bash
- Build the rest
  - colcon build
- Build Reflexxes library.
  - Download and extract Reflexxes in some directory, say:
    - `mkdir -p ~/src/reflexxes`
    - `unzip ~/Downloads/ReflexxesTypeII.zip -d ~/src/reflexxes/`
    - `cd ~/src/reflexxes/ReflexxesTypeII/Linux`
  - Patch makefile and run Make
    - `sed -i s/ddb/gdb/ Makefile.global`
    - `make all64`
  - Copy header files and library
    - `sudo cp x64/release/lib/shared/libReflexxesTypeII.so /usr/local/lib/`
    - `sudo cp ../include/* /usr/local/include/`

## Updating if installed repository before addition of submodules (commit: https://github.com/jdcast/rsp-final-project/commit/a74f598e87c174add4e3216217bd5e41983b91d4)
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
  - `git merge main` # solve merge conflicts if you have
  - `git push`

## Documentation:
- [Project Documenation](https://jdcast-rsp-final-project.readthedocs.io/en/latest/index.html#)
### Documentation Tools
- [Read the Docs](https://docs.readthedocs.io/en/stable/tutorial/index.html#getting-started)
- [Reproducible Builds](https://docs.readthedocs.io/en/stable/guides/reproducible-builds.html)
- [pip-tools](https://pip-tools.readthedocs.io/en/latest/)
- [sphinx](https://www.sphinx-doc.org/en/master/tutorial/getting-started.html#setting-up-your-project-and-development-environment)
- [Read the Docs Sphinx Theme](https://sphinx-rtd-theme.readthedocs.io/en/stable/)
- Pushes on `main` will trigger rebuilds at for [Project Documenation](https://jdcast-rsp-final-project.readthedocs.io/en/latest/index.html#)
- To View Locally:
  - cd `docs/source`
  - `sphinx-build -b html . ../build/html/`
  - point browser to `index.html` within `source/`
