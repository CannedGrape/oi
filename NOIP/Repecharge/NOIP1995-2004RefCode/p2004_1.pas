program unhappy(input,output);
var i,k,max:integer;
    a,b:integer;
begin
    assign(input,'unhappy.in');
    reset(input);
    assign(output,'unhappy.out');
    rewrite(output);
    k:=0;max:=8;		
    for i:=1 to 7 do begin
        readln(a,b);		
        if a+b>max then begin
             k:=i;max:=a+b;		
        end;		
    end;		
    close(input);		
    write(k);		
    close(output);		
end.		
