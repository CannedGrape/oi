program p2001_1(Input,output);
const maxn=10000;		
var I,j,n:Integer;		
    f:array[1..maxn] of longInt;		
begIn		
    assign(input,'count.in');
    reset(input);
    readln(n);
    close(input);		
    f[1]:=1;		
    for I:=2 to n dIv 2 do begIn		
        f[I]:=1;		
        for j:=1 to I dIv 2 do		
           f[I]:=f[I]+f[j];		
    end;		
    f[n]:=1;		
    for I:=1 to n dIv 2 do f[n]:=f[n]+f[I];
    assign(output,'count.out');
    rewrite(output);		
    wrIteln(f[n]);
    close(output);		
end.		

