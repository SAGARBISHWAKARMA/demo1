cmd_/home/sagarbike/git/demo/task4/Module.symvers := sed 's/\.ko$$/\.o/' /home/sagarbike/git/demo/task4/modules.order | scripts/mod/modpost -m -a  -o /home/sagarbike/git/demo/task4/Module.symvers -e -i Module.symvers   -T -
