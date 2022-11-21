FROM ubuntu:latest

RUN apt update && apt install -y git python3 python3-pip sudo

RUN python3 -m pip install --user qmk

VOLUME /qmk_firmware
WORKDIR /qmk_firmware

ENV PATH="/root/.local/bin:$PATH"

RUN qmk setup

ENTRYPOINT ["/root/.local/bin/qmk"]
