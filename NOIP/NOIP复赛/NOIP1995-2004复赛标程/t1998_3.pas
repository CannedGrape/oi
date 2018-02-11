program t1998_3;
const maxn=9;
var n,i,j:integer;
    s:array[1..maxn,1..maxn]of string[2];
    v:array['A'..'Z']of integer;
    c:string;
    count:integer;
    flag:boolean;

procedure change(c:string;i:integer);
var j,kc,ks:integer;
begin
    j:=1;kc:=1;
    while kc<=length(c) do begin
        ks:=1;
        while (c[kc]<>' ') and (kc<=length(c)) do begin
            s[i,j][ks]:=c[kc];
            ks:=ks+1;
            kc:=kc+1;
        end;
        s[i,j][0]:=chr(ks-1);
        j:=j+1;
        kc:=kc+1;
    end;
end;

begin
    assign(input,'rusi.in');
    reset(input);
    readln(n);
    for i:=1 to n do begin
       readln(c);
       change(c,i);
    end;
    close(input);
    assign(output,'rusi.out');
    rewrite(output);
    for i:=0 to 25 do v[chr(ord('A')+i)]:=-1;
    count:=0;
    flag:=false;
    while not flag and (count<n-1) do begin
        flag:=true;
        for i:=2 to n do
          for j:=2 to n do begin
             if (s[i,j]=s[i,1]) then
                 if (v[s[1,j][1]]=-1) then begin
                      count:=count+1;
                      flag:=false;
                      v[s[1,j][1]]:=0;end
                 else if v[s[1,j][1]]<>0 then
                     begin write('ERROR!');close(output);halt;end;
             if (s[i,j]=s[1,j]) then
                 if (v[s[i,1][1]]=-1) then begin
                     count:=count+1;
                     flag:=false;
                     v[s[i,1][1]]:=0;end
                 else if v[s[i,1][1]]<>0 then
                    begin write('ERROR!');close(output);halt;end;
             if (length(s[i,j])>1) then
                 if (v[s[i,j][1]]=-1) then begin
                     count:=count+1;
                     flag:=false;
                     v[s[i,j][1]]:=1;end
                 else if v[s[i,j][1]]<>1 then
                     begin write('ERROR!');close(output);halt;end;
             if (length(s[i,j])=1) and (v[s[i,1][1]]<>-1) and (v[s[1,j][1]]<>-1) then
                 if (v[s[i,j][1]]=-1) then begin
                     count:=count+1;
                     flag:=false;
                     v[s[i,j][1]]:=v[s[i,1][1]]+v[s[1,j][1]];end
                 else if v[s[i,j][1]]<>v[s[i,1][1]]+v[s[1,j][1]] then
                     begin write('ERROR!');close(output);halt;end;
          end;
    end;
    if count=n-1 then begin
        write(s[1,2],'=',v[s[1,2][1]]);
        for j:=3 to n do write(' ',s[1,j],'=',v[s[1,j][1]]);
        writeln;
        for i:=2 to n do
           for j:=2 to n do
              if length(s[i,j])>1 then begin
                  writeln(v[s[i,1][1]]+v[s[1,j][1]]-v[s[i,j][2]]);
                  close(output);
                  halt;
              end;
    end
    else writeln('ERROR!');
    close(output);
end.
