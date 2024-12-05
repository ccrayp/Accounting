mkdir build
cd source
g++ Accounting.cpp processing.cpp check.cpp data.cpp -o ../build/Accounting
echo "Проект был собран в директории ./build, для запуска перейдите в директорию сборки и запустите start.sh"
cd ../build
touch start.sh
echo -e "#!/bin/bash\nchmod +x Accounting\n./Accounting" > start.sh
chmod +x start.sh
