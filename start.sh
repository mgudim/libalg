docker run \
    -it \
    -v $(pwd):/home/project \
    -w /home/project \
    --privileged \
    mgudim/libds:latest
