# emacs_atclib
atclib's emacs with full IDE feature enabled

# Install below packages 
sudo apt-get install emacs23 cscope cscope-el

# Configuration: We need to configure emacs to load cscope support, edit your ~/.emacs or ~/.emacs.d/init.el to include following line.
(require 'xcscope)

# If didnt work : check your xcscxope.el path
(load-file "/usr/share/emacs/site-lisp/xcscope.el")
(require 'xcscope)

# Used attach cscope script and run on your project : Assume script.cscope kept at directory ~/bin/
~/bin/script.cscope

# Build ctags
cscope -b

# Use ctgags or can used with EMACS             
cscope -d 

# Ref :
https://techtooltip.wordpress.com/2012/01/06/how-to-integrate-emacs-cscope-to-browse-linux-kernel-source-code/ 

http://martinezjavier.blogspot.com/2011/07/emacs-configuration-for-linux-kernel.html


https://techtooltip.wordpress.com/2012/01/06/how-to-integrate-emacs-cscope-to-browse-linux-kernel-source-code/

https://www.emacswiki.org/emacs/CScopeAndEmacs

https://emacs.stackexchange.com/questions/9499/emacs-cscope-integration-basics



https://github.com/remirobert/emacs-config/tree/master/version2


copy ecb stuff from atul to new one

Install ecb-snapshot
M-x package-list-packages

; from http://stackoverflow.com/questions/8833235/install-ecb-with-emacs-starter-kit-in-emacs-25
(setq stack-trace-on-error t)
(setq ecb-version-check nil)
static void stop_timer(void)
{
del_timer(&pdata->ddr_bw_timer);

Line Number Mode :
http://ergoemacs.org/emacs/emacs_line_number_mode.html
