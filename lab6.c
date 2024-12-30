git checkout feature-branch
vi file5.txt
git add file5.txt
git commit -m"1st line of FB(v1)"
git checkout master
git merge feature-branch
git log
