# Use the official GCC image
FROM gcc:latest

# Install OpenSSL development headers
RUN apt-get update && apt-get install -y libssl-dev
