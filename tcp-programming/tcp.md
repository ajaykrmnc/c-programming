# Heading

## Sub-Heading

```serveraddress.sin_family = AF_INET;

    connection = connect(socket_file_descriptor, (SA *)&serveraddress, sizeof(serveraddress));

    if(connection == -1){
        printf("Connection with the server failed\n");
        exit(1);
    }
```
