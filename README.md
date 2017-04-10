# NOPcert-2017
NOP Certification Challenges from Infiltrate 2017

## Machine Setup

To setup the VM:

- Install Ubuntu 16.06 x64
- Disable ASLR: ```echo kernel.randomize_va_space = 0  | sudo tee /etc/sysctl.d/01-disable-aslr.conf ```
- Enable ptrace: ```sudo sed -i 's/kernel.yama.ptrace_scope = 1/kernel.yama.ptrace_scope = 0/' /etc/sysctl.d/10-ptrace.conf ```
- Install xinetd.conf: ```sudo apt install xinetd```
- Enable xinet profile: ```sudo cat > /etc/xinetd/chal1 << **
service chal1
{
		disable = no
		socket_type = stream
		protocol = tcp
		user = root
		wait = no
		server = /root/chal1
		port = 9999
}```

## Compile the binaries

```make```
