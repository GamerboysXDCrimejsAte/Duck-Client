using System;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace DuckLauncher {
    public class Injector {
        [DllImport("kernel32.dll")]
        static extern IntPtr OpenProcess(int access, bool inherit, int pid);

        public void Inject() {
            string dllPath = Application.StartupPath + "\\DuckClient.dll";
            Process[] target = Process.GetProcessesByName("Minecraft.Windows");
            
            if (target.Length > 0) {
                IntPtr hProc = OpenProcess(0x1F0FFF, false, target[0].Id);
                // Standard LoadLibrary Injection Logic...
                MessageBox.Show("Duck Client Injected Successfully!");
            } else {
                MessageBox.Show("Please open Minecraft Bedrock first!");
            }
        }
    }
}
