Open Vscode
- Press F1 and select "Remote-SSN: Connect to host" 
- type in the following 


git clone https://github.com/drewborchert-debug/Final_Project.git
cd Final_Project

qmake -project
echo "QT += widgets" >> Final_Project.pro
qmake
make


call a main terminal window 


Log into a linex 
ssh -Y dborchert@cs01.richmond.edu

cd ~to whatever the final project is in
./Final_Project