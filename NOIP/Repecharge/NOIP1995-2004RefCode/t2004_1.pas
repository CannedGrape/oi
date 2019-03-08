program save(input,output);
var total,sum,i,c:integer;
    s:array[1..12]of integer;
begin
    assign(input,'save.in');
    assign(output,'save.out');
    reset(input);
    rewrite(output);
    total:=0;sum:=0;
    for i:=1 to 12 do begin
       total:=total+300;
       readln(s[i]);
       if total<s[i] then begin write(-1*i);close(output);halt;end
          else begin
              total:=total-s[i];
              c:=total div 100;
              sum:=sum+c*100;
              total:=total -c*100;
          end;
    end;
    close(input);
    writeln(total+sum*1.2:0:0);
    close(output);
end.
