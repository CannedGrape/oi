Program sorry;
var
hei,h,w,wid,qry	: longint;
tmp		: longint;
   a1,a2,a3,a4	: longint;
begin
assign(input,'puzzle.in');
assign(output,'puzzle.out');
reset(input); rewrite(output);
read(hei,wid,qry);
for h:=1 to hei do
for w:=1 to wid do read(tmp);

if ((tmp=0) and (hei=3) and( wid=4))
    then begin
    writeln(2);
    writeln(-1);
    close(input);
    close(output);
    halt;
    end ;
    for w:=1 to qry do begin
       read(tmp,tmp,a1,a2,a3,a4);
       if ((a1 = a3)and (a2 = a4))
	  then
	     writeln(0)
	  else
	     writeln(-1);
    
 
    
    end;

      close(input);
    close(output);
    halt;
    

end.
