### In this phase, we analysed and exploit security breach on a binary. We mainly used the tool Ghidra ![](/images/Ghidra_Logo2.png) and the debugger gdb. Manual helped us a lot.  

**Vulnerabilities are classified according to this nomenclature:**  
* $${\color{magenta}Critical}$$  
* $${\color{red}High}$$  
* $${\color{darkorange}Medium}$$  
* $${\color{green}Info}$$  

_You can find in the_ <code>bootstrap_pdf</code> _directory a list of pdf describing the type of vulnerabilities we mainly encounter. Each pdf is encrypted, so we let a note with all the password._

> [!IMPORTANT]
> We have list vulnerabilities in a website using a framework named Dradis.                                                                              
> Here is the link : http://217.154.17.238/login                                                                                                                              
> And the password :grin: : 6bc18ec1c7513ba5f427a2c3634442f4


---

### Exploit #1 :
**Location** : `activate_emergency_protocols`


**Black-box :**

- Vulnerability 1: <br />
    Severity: Critical <br />
    Exploit Type: Sensitive information hard-coded <br />
    Description: The function is waiting for user to type admin password while its hard coded. <br />
    Proof of Concept: <br />
    ![](/images/admin4242_1.png)  
    <br />
    Impact: A simple user can do anything he want. <br />
    Recommendation: Encrypt the password. <br />

**White-box :**

*(No vulnerability found)*


---

### Exploit #2 :
**Location** : `check_cooling_pressure`


**Black-box :**

- Vulnerability 1: <br />
    Severity: Critical <br />
    Exploit Type: Use-after-free <br />
    Description: A variable is free, then used by a function of the libc. <br />
    Proof of Concept: <br />
    ![](/images/{sensitive_data}.png) <br />
    Impact: When check_cooling_function’s function is called, sensitive data is retrieved. <br />
    Recommendation: Set the pointer of the variable to NULL after free. <br />

**White-box :**

*(No vulnerability found)*


---

### Exploit #3 :
**Location** : `check_reactor_status`


**Black-box :**

- Vulnerability 1: <br />
    Severity: Critical <br />
    Exploit Type: Weak encryption <br />
    Description: The program is crypting critical reactor data with casear encryption, leading to a vulnerability by decrypting the code easily. <br />
    Proof of Concept: We can either read the source code to find which encryption we are using, or bruteforce the data output of the program. <br />
    ![](/images/reactor_status_black_box.png) <br />
    = <br />
    ReactorStatusOK <br />
    Impact: Everybody can access easily the reactor critical data. <br />
    Recommendation: Use stronger encryption algorithm with function crypt for example (sha256). <br />

**White-box :**

*(No vulnerability found)*


---

### Exploit #4 :
**Location** : `configure_cooling_system`


**Black-box :**

- Vulnerability 1: <br />
    Severity: Critical <br />
    Exploit Type: Command injection <br />
    Description: The function call the function “system” from the libc and doesen’t check the input of the user. <br />
    Proof of Concept: Create a file named “./Data/cooling_config.txt” and write “exec [cmd]” and call configure_cooling_system.  <br />
    ![](/images/configure_cooling_system.png) <br />
    Impact: 
    - User can execute malicious command to retrieve sensitive data (example : cat /etc/passwd).
    - User can crash the program.
     <br />
    Recommendation: Don't use the function "system", especially if you send the user input in its parameter. <br />

**White-box :**

*(No vulnerability found)*


---

### Exploit #5 :
**Location** : `load_fuel_rods`


**Black-box :**

- Vulnerability 1: <br />
    Severity: Critical <br />
    Exploit Type: Type confusion <br />
    Description: The function is waiting for the user to enter the number of fuel rods to load. <br />
    Proof of Concept: <br />
    ![](/images/the_secret_stone_is_here.png) <br />
    Impact: Unexpected behavior : compromised data in the output. <br />
    Recommendation: Make sure the input value is a numerical value and not a string, should use strtol function. <br />

**White-box :**

*(No vulnerability found)*


---

### Exploit #6 :
**Location** : `log_system_events`


**Black-box :**

- Vulnerability 1: <br />
    Severity: Critical <br />
    Exploit Type: Sensitive data exposure <br />
    Description: The function is waiting for user entry, then it wrotes in a Data/system.log the command. However if you type “leak”, you can read sensitive data in the file. <br />
    Proof of Concept: <br />
    ![](/images/secret_log_12pierre34.png) <br />
    Impact:  Sensitives data are exposed. <br />
    Recommendation: 
    - Authentication whenever the command “leak” is typed
    - Strict file access on system.log  <br />

**White-box :**

*(No vulnerability found)*


---

### Exploit #7 :
**Location** : `monitor_radiation_levels`


**Black-box :**

- Vulnerability 1: <br />
    Severity: Critical <br />
    Exploit Type: Buffer overflow <br />
    Description: The function is waiting for the user to enter radiation levels. However the buffer allocated is static and very low, leading to a segfault for an input of 10 or more characters. <br />
    Proof of Concept: <br />
    Call the function and write a string with 10+ characters <br />
    ![](/images/monitor_radiation_levels.png)  <br />
    Impact:  Program crash and memory vulnerable. <br />
    Recommendation: Check the length of the string. <br />

**White-box :**

*(No vulnerability found)*


---

### Exploit #8 :
**Location** : `run_diagostic`


**Black-box :**

- Vulnerability 1: <br />
    Severity: Critical <br />
    Exploit Type: Sensitive data exposure <br />
    Description: The program offers a debug mode in run_diagnostic function. However everybody can acess the debug mode. <br />
    Proof of Concept: <br />
    ![](/images/secret_diagnostic_key.png) <br />
    Impact: Reactor functionnement compromised. <br />
    Recommendation: * Encrypt password in code source<br />* Multiple authentication <br />

**White-box :**

*(No vulnerability found)*


---

### Exploit #9 :
**Location** : `send_status_report`


**Black-box :**

- Vulnerability 1: <br />
    Severity: Medium <br />
    Exploit Type: Hard-coded encryption <br />
    Description: The program is crypting some sensitive data in base64. <br />
    Proof of Concept: We can either read the source code to find which encryption we are using, or bruteforce the data output of the program.  <br />
    ![](/images/send_status_report_black_box.png) <br />
    = <br />
    Hostname: localhost  <br />
    IP Address: 127.0.0.1  <br />
    Process: pipeto (PID: 1234) <br />
    Impact : If a user get the source code, he can decrypt some sensitive keys/passwords. <br />
    Recommendation: Use stronger encryption algorithm with function crypt for example (sha256). <br />

**White-box :**

*(No vulnerability found)*

---

### Exploit #10 :
**Location** : `set_reactor_power`


**Black-box :**

- Vulnerability 1: <br />
    Severity: Critical <br />
    Exploit Type: Integer overflow <br />
    Description: The user is asked to enter the reactor power, but the function doesn’t check the value. If we exceed the maximum value of a int, the reactor EXPLODE. <br />
    Proof of Concept: <br />
    ![](/images/12explosion34.png) <br />
    Impact : Explosion <br />
    Recommendation: Check the value entered by the user, and set a limit. <br />

**White-box :**

*(No vulnerability found)*

---

### Exploit #11 :
**Location** : `simulate_meltdown`


**Black-box :**

- Vulnerability 1: <br />
    Severity: Critical <br />
    Exploit Type: Sensitive data exposure by bruteforce <br />
    Description: The program is generating a “fake” random value to simulate the meltdown, they are several output depending on which value is generated and for < 5 the secret code leaks. <br />
    Proof of concept:  <br />
    ![](/images/meltdown1234.png)  <br />
    Impact : Sensitive value is accessible. <br />
    Recommendation: <br />
    - Generating “true random” can be good <br />
    - Encrypt sensitive data <br />
    - Adding delay can lower the bruteforce attacks efficiency
 <br />

**White-box :**

*(No vulnerability found)*

---

### Exploit #12 :
**Location** : `trigger_emergency_shutdown`


**Black-box :**

- Vulnerability 1: <br />
    Severity: Critical <br />
    Exploit Type: Sensitive Access <br />
    Description: The function recquires admin rights to shutdown the reactor. We can use previous exploits to escalate priviliage as admin (have a look at {Emergency protocols activated, you are now admin !} ) Once admin we only have to call the trigger_emergency_shutdown function. <br />
    Proof of concept: <br />
    ![](/images/shutdown.png)  <br />
    Impact :  Reactor functionnement compromised. <br />
    Recommendation: <br />
    - Encrypt password in code source <br />
    - Multiple authentication
. <br />

**White-box :**

*(No vulnerability found)*

---

### Exploit #13 :
**Location** : `unlock_secret_mode`


**Black-box :**

- Vulnerability 1: <br />
    Severity: Critical <br />
    Exploit Type: Sensitive data exposure <br />
    Description: The program is not showing every function, the unlock secret mode function is hidden but can be retrieve by reversing the code and analyzing it. Now that we now that it exits we can call it but nothing happened. In order to trigger the sensitive data, we need before to exploit a previous vulnerability by calling the activate_emergency_protocols and type the password we already found. Once done we are in the system as admin and we can now call unlock_secret_mode and access sensitive data. <br />
    Proof of concept: <br />
    ![](/images/admin4242_1.png)  <br />
    ![](/images/admin4242_2.png) <br />
    Impact :  Sensitive data is exposed as admin. <br />
    Recommendation: <br />
    - Multiplying password for different access in case one leak. <br />
    - Not set admin as global value but as authentication, or token. <br />
. <br />

**White-box :**

*(No vulnerability found)*

---

### Exploit #14 :
**Location** : `load_config`


**Black-box :**

- Vulnerability 1: <br />
    Severity: Critical <br />
    Exploit Type: Sensitive data exposure <br />
    Description: The function is reading from a file (./config.ini), writing the readed file of 100 bytes into a buffer of 8 bytes. <br />
    Proof of concept: warning: ‘read’ writing 100 bytes into a region of size 8 overflows the destination [-Wstringop-overflow=]  
   35 |     read(fd, array, 100);  <br />
   ![](/images/load_config.png)  <br />
    Impact :  Maliscious code can be injected anywhere. <br />
    Recommendation: <br />
    - Writing less bytes
    - Adding a larger size to the buffer
. <br />

**White-box :**

*(No vulnerability found)*

---

### Exploit #15 :
**Location** : `library -> turbine_remote_access`


**Black-box :**

- Vulnerability 1: <br />
    Severity: Critical <br />
    Exploit Type: File permission <br />
    Description: The {ACCESS_GRANTED} value is written in a temporary file located in the Data/ directory. This file is created with insufficient protection and remains accessible to external users during the program’s execution, allowing unauthorized access to sensitive information. <br />
    Proof of concept: <br />
    ![](/images/access_granted.png) <br />
    Impact :  Guaranty access to turbine remote control. <br />
    Recommendation: Use strict permissions when creating the file or immediately ulink the file. 
. <br />

**White-box :**

*(No vulnerability found)*

---

### Exploit #16 :
**Location** : `library -> run_turbine`


**Black-box :**

- Vulnerability 1: <br />
    Severity: Info <br />
    Exploit Type: Integer undeflow <br />
    Description: The program is waiting for an user to type the number of rotation the turbine will do. However it is not checking if the entry is a negative value, and its bad handling of int and usigned int value leads to turbine spinning to fast and can’t stop. <br />
    Proof of concept: ![](/images/run_turbine.png) <br /> <br />
    Impact :  Turbine can’t stop. <br />
    Recommendation: <br />
    Filter entry value, use unsigned int everywhere.
. <br />

**White-box :**

*(No vulnerability found)*

---

### Exploit #17 :
**Location** : `library -> turbine_temperature`


**Black-box :**

- Vulnerability 1: <br />
    Severity: Critical <br />
    Exploit Type: Buffer Overflow <br />
    Description: The program is checking if the entry value is not exceeding a certain value max and min, but if it reach it exactly, it explodes. <br />
    Proof of concept:  <br />
    ![](/images/error_turbine_will_explode.png) <br />
    Impact :  BOOM !!! <br />
    Recommendation: <br />
    Verify value before casting as int.
. <br />

**White-box :**

*(No vulnerability found)*

---

### Exploit #18 :
**Location** : `load_pipetorc`


**Black-box :**

- Vulnerability 1: <br />
    Severity: Critical <br />
    Exploit Type: Format string <br />
    Description: The function is retrieving user input and put it in a printf without format. <br />
    Proof of concept: warning: format not a string literal and no format arguments [-Wformat-security]  
   44 |           printf(line);  <br />
    Impact :  Crash the program or execute harmful code. <br />
    Recommendation: <br />
    Specidy the format string.
. <br />

**White-box :**

*(No vulnerability found)*

---

### Exploit #19 :
**Location** : `caesar_crypt_reactor_data`


**Black-box :**

- Vulnerability 1: <br />
    Severity: Critical <br />
    Exploit Type: Buffer Overflow <br />
    Description: The program is crypting critical reactor data with casear encryption, leading to a vulnerability by decrypting the code easily. <br />
    Proof of concept: We can either read the source code to find which encryption we are using, or bruteforce the data output of the program. add image <br />
    Impact :  Everybody can access easily the reactor critical data. <br />
    Recommendation: <br />
    Use stronger encryption algorithm with function crypt for example (sha256).
. <br />

**White-box :**

*(No vulnerability found)*

---

### Exploit #20 :
**Location** : `check_pepitorc`


**Black-box :**

- Vulnerability 1: <br />
    Severity: Critical <br />
    Exploit Type: Sensitive data exposure <br />
    Description: The function call the function “system” from the libc and doesen’t check the input of the user. <br />
    Proof of concept: Create a file named “.pipetorc” and write “exec [cmd]” and launch the program. <br />
    ![](/images/check_pipetorc.png) <br />
    Impact :  
    - User can execute malicious command to retrieve sensitive data (example : cat /etc/passwd).
    - User can crash the program. <br />
    Recommendation: <br />
    Don’t let the user input in the function.
. <br />

**White-box :**

*(No vulnerability found)*

---

### Exploit #21 :
**Location** : `dispatch_commands`


**Black-box :**

- Vulnerability 1: <br />
    Severity: High <br />
    Exploit Type: Core dump <br />
    Description: The program is using recursivity whenever using the “!n” command to retrieve old commands in history. However if “!n” command found its self in history, the recursivity goes infinite and then lead to segfault core dump. <br />
    Proof of concept: Launch program and type “!n” (for n being the id of the command !n in your history, you can delete history and type “!1” to test). <br />
    ![](/images/history_recursivity_issue.png) <br />
    Impact :  
    - Program crash if user call “!n” and “!n” being in history commands.
    - Recommendation: <br />
    Filter input values.
. <br />

**White-box :**

*(No vulnerability found)*

---

### Exploit #22 :
**Location** : `dynamic library`


**Black-box :**

- Vulnerability 1: <br />
    Severity: ? <br />
    Exploit Type: ? <br />
    Description: ? <br />
    Proof of concept: ? <br />
    Impact ? :  
    Recommendation: ? <br />

**White-box :**

*(No vulnerability found)*

---

### Exploit #23 :
**Location** : `Found Credentials`


**Black-box :**

- Vulnerability 1: <br />
    Severity: ? <br />
    Exploit Type: ? <br />
    Description: ? <br />
    Proof of concept: ? <br />
    Impact ? :  
    Recommendation: ? <br />

**White-box :**

*(No vulnerability found)*
