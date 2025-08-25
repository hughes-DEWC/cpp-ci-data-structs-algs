FROM registry.access.redhat.com/ubi9/ubi:latest

ARG USER_ID=1001
ARG GROUP_ID=1001
ENV USER_NAME=default

ENV HOME="/home/${USER_NAME}"
ENV PATH="${HOME}/.local/bin:${PATH}"

USER root

# Check for package update
RUN dnf -y update-minimal --security --sec-severity=Important --sec-severity=Critical && \
# Install git, nano & clang, cmake, gcc-c++, ninja-build, meson, gdb
dnf install git nano clang cmake gcc-c++ ninja-build meson gdb -y; \
# Clear cache
dnf clean all

# Create user and set permissions
RUN groupadd -g ${GROUP_ID} ${USER_NAME} && \
    useradd -u ${USER_ID} -r -g ${USER_NAME} -m -d ${HOME} -s /bin/bash ${USER_NAME}

# Run as User
USER ${USER_NAME}
