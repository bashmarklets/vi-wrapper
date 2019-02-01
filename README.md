# vi(m) wrapper
Do you find yourself doing a `grep -rn` through a code base looking for an given log line or function call, then doing a quick `vi <file>.src` followed by a `:382` to jump to the relevant line?

Wouldn't it be nicer if you could just open that line directly using the `grep -rn` output?

The `vi` wrapper script intends to do exactly that, a shorthand and intuitive way to open files.

Any of the below should work as you would expect:
```bash
$ vi file.ext
$ vi file.ext:23
$ vi file.ext-24
$ vi file.ext 23
$ vi file.ext:23:	if [ ...
$ vi file.ext-24-		local ...
```

Also feel free to rename the function `vim` if you are more familiar typing that.

If you like this then you may want to check out the `less` equivalent [less-wrapper](https://github.com/bashmarklets/less-wrapper).

## Example use case
```bash
[bash@marklet:~/]
$ grep -rn _VI_WRAPPER_BIN bashmarklets/
bashmarklets/vi-wrapper/vi_wrapper.inc:7:	if [ ! -z "${_VI_WRAPPER_BIN}" ]; then
bashmarklets/vi-wrapper/vi_wrapper.inc:8:		local VI=${_VI_WRAPPER_BIN}

[bash@marklet:~/]
$ vi bashmarklets/vi-wrapper/vi_wrapper.inc:8:
```

## How to install

Either download/clone this repository and add the following to your `~/.bashrc` file:
```bash
source path/to/vi_wrapper.inc
```

or alternatively just copy-paste the function directly into your `~/.bashrc` file.

NB: The source approach is recommended if you end up picking up more than one of these bookmarklets as it avoids clutter.
